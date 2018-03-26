#include"error.h"

#define UNUSED_PARAMETER(name) (void)name

err_t ErrCheck(err_t my_err)
{
	UNUSED_PARAMETER(my_err);
	return ERR_OK;
}

void ErrPrint(err_t my_err)
{
	UNUSED_PARAMETER(my_err);
}
