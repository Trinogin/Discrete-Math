#include"interface.h"

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
	UNUSED_PARAMETER(string);
	UNUSED_PARAMETER(my_num);
	UNUSED_PARAMETER(error);
}