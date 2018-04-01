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
	char* hptr = NULL;
	char name;
	int par_1;
	int par_2;

	while (string[i] != '\0')
	{
		string[i] = (char)tolower(string[i]);
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
		if (isalpha(string[i]))
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
	if (string[i] == '\0')
	{
		*error = ERR_OK;
		return;
	}
	if (isalpha(string[i]))
	{
		name = string[i];
		//fprintf(stdout, "%c %i %i \n", my_num->name, my_num->par_1, my_num->par_2);
		if (!isalpha(string[i + 1]))
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
			//while (isdigit(string[i]))
			//{

			//}

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

}

void LineParse(char* argv[], class_num* my_num, err_t* error)
{
	char* str1 = NULL;
	char* str2 = NULL;
	char* str3 = NULL;

	UNUSED_PARAMETER(my_num);

	str1 = (char*)malloc(sizeof(char) * (strlen(argv[1]) + 1));
	str2 = (char*)malloc(sizeof(char) * (strlen(argv[2]) + 1));
	str3 = (char*)malloc(sizeof(char) * (strlen(argv[3]) + 1));

	if (str1 == NULL || str2 == NULL || str3 == NULL)
	{
		if (str1 != NULL)
			free(str1);
		if (str2 != NULL)
			free(str2);
		if (str3 != NULL)
			free(str3);
		*error = ERR_NOT_ENOUGH_MEM;
		return;
	}

	strcpy(str1, argv[1]);
	strcpy(str2, argv[2]);
	strcpy(str3, argv[3]);

	//fprintf(stdout, "%s \n", str1);
	//fprintf(stdout, "%s \n", str2);
	//fprintf(stdout, "%s \n", str3);

	if (str1 != NULL)
		free(str1);
	if (str2 != NULL)
		free(str2);
	if (str3 != NULL)
		free(str3);
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