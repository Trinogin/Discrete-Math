#include"error.h"

// out of domain (with negative values) is included in incorrect command
void ErrPrint(err_t my_err)
{
	switch (my_err)
	{
	case ERR_INCORRECT_STRING:
		fprintf(stderr, "Error: incorrect command entered \n");
		break;
	case ERR_NOT_ENOUGH_MEM:
		fprintf(stderr, "Error: not enough memory \n");
		break;
	case ERR_BAD_COMPUTING:
		fprintf(stderr, "Error: problems in computing \n");
		break;
	case ERR_OUT_OF_DOMAIN:
		fprintf(stderr, "Error: incorrect values \n");
		break;
	}
}