#include"error.h"

void ErrPrint(err_t my_err)
{
	switch (my_err)
	{
	case ERR_INCORRECT_STRING:
		fprintf(stderr, "Error: incorrect string entered \n");
		break;

	case ERR_NOT_ENOUGH_MEM:
		fprintf(stderr, "Error: not enough memory \n");
		break;
	}
}
