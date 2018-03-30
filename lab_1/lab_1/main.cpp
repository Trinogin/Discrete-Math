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
	if (argc > 1)
	{
		LineParse(argv, my_num, &my_err);
		if (my_err != ERR_OK)
			ErrPrint(my_err);

		return 0;
	}


	fprintf(stdout, "Enter command or 'help' (h) \n");

	//HelpPrint(stdout);

	while ((string_in = ReadLine(stdin)) != NULL)
	{
		//fprintf(stdout, "%s \n", string_in);
		//---------------------------------------------------------------------------------
		// Here only parsing errors, errors with parameters is in class constructor
		ParseString(string_in, my_num, &my_err);
		fprintf(stdout, "%s \n", string_in);
		if (my_err != ERR_OK)
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