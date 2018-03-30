#include"interface.h"
#include"impl.h"





/* Dynamic string reading */
/* Not for reading from file */
char* ReadLine(FILE* stream)
{
	char* str1 = NULL;
	char* str2 = NULL;
	char ch;
	int num;

	num = 1;

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
	bool bracket_fl_st = false;
	bool bracket_fl_end = false;
	char* hptr = NULL;

	UNUSED_PARAMETER(my_num);

	while (string[i] != '\0')
	{
		string[i] = (char)tolower(string[i]);
		i++;
	}

	if (!(bracket_fl_st * bracket_fl_end) && bracket_fl_st != false && bracket_fl_end != false)
	{
		*error = ERR_INCORRECT_STRING;
		return;
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

	i = 0;
	while (string[i] != '\0')
	{
		SpaceSkip(string);
		i++;
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