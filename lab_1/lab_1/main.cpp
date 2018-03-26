#include<iostream>
#include<fstream>
#include<vld.h>
#include"interface.h"


#define MAX_PARAMS_NUM 4

using namespace std;

int main(int argc, char* argv[])
{
	char* string_in;
	class_num* my_num = NULL;
	err_t my_err = ERR_OK;
	
	if (argc > MAX_PARAMS_NUM)
	{
		fprintf(stderr, "Error: too much parameters \n");
		return -1;
	}

	fprintf(stdout, "Enter command or 'help' (h) \n");

	while ((string_in = ReadLine(stdin)) != NULL)
	{
		fprintf(stdout, "%s \n", string_in);
//---------------------------------------------------------------------------------
		// Here only parsing errors, errors with parameters is in class constructor
		ParseString(string_in, my_num, &my_err);

		if (ErrCheck(my_err) != ERR_OK)
		{
			ErrPrint(my_err);
			if (string_in != NULL)
				free(string_in);
		}
//---------------------------------------------------------------------------------
		if (string_in != NULL)
			free(string_in);
		my_err = ERR_OK;
	}

	UNUSED_PARAMETER(argv);

	return 0;
}