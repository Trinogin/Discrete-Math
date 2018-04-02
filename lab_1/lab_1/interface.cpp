#include"interface.h"
#include"impl.h"

/* Dynamic string reading */
/* Not for reading from file */
char* ReadLine(FILE* stream)
{
	char* str1 = NULL;
	char* str2 = NULL;
	char ch;
	int num = 1;

	while (((ch = (unsigned char)getc(stream)) != '\n'))
	{
		if (ch == EOF)
		{
			return NULL;
		}
		str2 = (char*)realloc(str1, num * sizeof(char));
		if (str2 != NULL)
		{
			str1 = str2;
			str1[num - 1] = ch;
			num++;
		}
		else
		{
			free(str1);
			str1 = NULL;
			str2 = NULL;
			fprintf(stderr, "Error: not enough memory for reading parameters \n");
			return NULL;
		}
	}

	str2 = (char*)realloc(str1, num * sizeof(char));
	if (str2 != NULL)
	{
		str1 = str2;
		str1[num - 1] = '\0';
		num++;
	}
	else
	{
		free(str1);
		str1 = NULL;
		str2 = NULL;
		fprintf(stderr, "Error: not enough memory for reading parameters \n");
		return NULL;
	}

	return str1;
}

void ParseString(char* string, class_num* my_num, err_t* error)
{
	int i = 0;
	int j = 0;
	char* hptr = NULL;
	char digit[] = { '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };
	char name;
	int par_1;
	int par_2;
	int par_num = 0;
	bool err_nc = false; // err for num class constructor

	while (string[i] != '\0')
	{
		string[i] = (char)tolower(UCHAR string[i]);
		i++;
	}

	hptr = strstr(string, "help");
	if (hptr != NULL)
	{
		i = 1;
		while (i < 4)
		{
			hptr[i] = ' ';
			i++;
		}
	}
	else
	{
		i = 0;
		i = SpaceSkip(string, i);
		i++;
		i = SpaceSkip(string, i);
		if (isalpha(UCHAR string[i]))
		{
			*error = ERR_INCORRECT_STRING;
			return;
		}
	}

	i = 0;
	i = SpaceSkip(string, i);

	if (string[i] == 'h')
	{
		*error = ERR_HELP_NEED;
		return;
	}
	if (string[i] == 'q')
	{
		*error = ERR_QUIT;
		return;
	}


	if (string[i] == '\0')
	{
		*error = ERR_OK;
		return;
	}
	if (isalpha(UCHAR string[i]))
	{
		name = string[i];
		if (!isalpha(UCHAR string[i + 1]))
		{
			i++;
			i = SpaceSkip(string, i);
			if (string[i] != '(')
			{
				*error = ERR_INCORRECT_STRING;
				return;
			}
			i++;
			i = SpaceSkip(string, i);
			j = 0;
			while (isdigit(UCHAR string[i]) && j < MAX_SYM_NUM)
			{
				digit[j] = string[i];
				i++;
				j++;
			}
			if (j == 10)
			{
				*error = ERR_BAD_COMPUTING;
				return;
			}
			if (digit[0] == '\0')
			{
				*error = ERR_INCORRECT_STRING;
				return;
			}
			// 1st parameter end
			par_1 = atoi(digit);
			par_num++;
			i = SpaceSkip(string, i);
			if (string[i] == ',')
				i++;
			else
			{
				i = SpaceSkip(string, i);
				if (string[i] != ')')
				{
					*error = ERR_INCORRECT_STRING;
					return;
				}
				else
				{
					if (par_1 < 0)
					{
						*error = ERR_OUT_OF_DOMAIN;
						return;
					}
					my_num->name = name;
					my_num->par_1 = par_1;
					class_num::class_num(par_num, my_num, &err_nc);
					if (err_nc != false)
					{
						*error = ERR_INCORRECT_STRING;
						return;
					}
					return;
				}
			}

			j = 0;
			for (int n = 0; n < MAX_SYM_NUM; n++)
				digit[n] = '\0';
			i = SpaceSkip(string, i);

			while (isdigit(UCHAR string[i]) && j < MAX_SYM_NUM)
			{
				digit[j] = string[i];
				i++;
				j++;
			}
			if (j == 10)
			{
				*error = ERR_BAD_COMPUTING;
				return;
			}
			if (digit[0] == '\0')
			{
				*error = ERR_INCORRECT_STRING;
				return;
			}
			// 2nd parameter end
			par_2 = atoi(digit);
			par_num++;
			i = SpaceSkip(string, i);
			if (string[i] != ')')
			{
				*error = ERR_INCORRECT_STRING;
				return;
			}
		}
		else
		{
			*error = ERR_INCORRECT_STRING;
			return;
		}
	}
	else
	{
		*error = ERR_INCORRECT_STRING;
		return;
	}
	if (par_1 < 0 || par_2 < 0)
	{
		*error = ERR_OUT_OF_DOMAIN;
		return;
	}
	my_num->name = name;
	my_num->par_1 = par_1;
	my_num->par_2 = par_2;
	class_num::class_num(par_num, my_num, &err_nc);
	if (err_nc != false)
	{
		*error = ERR_INCORRECT_STRING;
		return;
	}
}

void LineParse(char* argv[], class_num* my_num, err_t* error)
{
	char* str1 = NULL;
	int sum_length;

	UNUSED_PARAMETER(my_num);


	sum_length = strlen(argv[1]) + strlen(argv[2]) + 2;

	if (argv[3] != NULL)
		sum_length += (strlen(argv[3]) + 1);

	str1 = (char*)calloc(sum_length, sizeof(char));
	strcat(str1, argv[1]);
	strcat(str1, argv[2]);
	strcat(str1, argv[3]);

	fprintf(stdout, "\n %s \n", str1);

	if (str1 != NULL)
		free(str1);
}

void HelpPrint(FILE* stream)
{
	char* str;
	int ch;
	FILE* file;
	int i = 0;

	file = fopen("HelpFile.txt", "r");
	if (file == NULL)
	{
		fprintf(stream, "Error with help \n");
		return;
	}
	while ((ch = getc(file)) != EOF)
		i++;

	fseek(file, SEEK_SET, 0);

	str = (char*)malloc((i + 1) * sizeof(char));
	if (str == NULL)
	{
		fprintf(stream, "Error with help \n");
		fclose(file);
		return;
	}

	fread(str, sizeof(char), i, file);
	str[i] = '\0';

	fprintf(stream, "%s \n", str);

	free(str);
	fclose(file);
}