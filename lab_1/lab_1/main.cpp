#include<iostream>
#include<fstream>
#include<vld.h>
#include"interface.h"

#define MAX_PARAMS_NUM 4

using namespace std;

int main(int argc, char* argv[])
{
	char* string_in;
	int result = 0;
	class_num my_num;
	class_num* my_num_ptr = &my_num;
	err_t my_err = ERR_OK;
	


	if (argc > MAX_PARAMS_NUM)
	{
		fprintf(stderr, "Error: too much parameters \n");
		return -1;
	}
	if (argc > 1)
	{
		LineParse(argv, my_num_ptr, &my_err);
		if (my_err != ERR_OK)
			ErrPrint(my_err);

		return 0;
	}

	fprintf(stdout, "%c %i %i \n", my_num.name, my_num.par_1, my_num.par_2);

	fprintf(stdout, "Enter command or 'help' (h) \n");

	while ((string_in = ReadLine(stdin)) != NULL)
	{
		fprintf(stdout, "%s == ", string_in);
		//---------------------------------------------------------------------------------
		// Here only parsing errors, errors with parameters is in class constructor
		ParseString(string_in, my_num_ptr, &my_err);
		//fprintf(stdout, "%s \n", string_in);
		if (my_err != ERR_OK)
		{
			if (my_err == ERR_HELP_NEED)
				HelpPrint(stdout);

			ErrPrint(my_err);
			if (string_in != NULL)
			{
				free(string_in);
				string_in = NULL;
			}
			my_err = ERR_OK;
			continue;
		}

		//result = my_num.class_num_comp(my_num,);
		fprintf(stdout, "%i \n", result);
		//---------------------------------------------------------------------------------
		if (string_in != NULL)
		{
			free(string_in);
			string_in = NULL;
		}
		my_err = ERR_OK;
	}

	UNUSED_PARAMETER(argv);

	return 0;
}