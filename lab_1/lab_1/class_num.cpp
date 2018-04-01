#include "class_num.h"

class_num::class_num()
{
	this->name = '0';
	this->par_1 = 0;
	this->par_2 = 0;
}

class_num::class_num(int par_num, char ch, int par_1, int par_2)
{

}

class_num::~class_num()
{
}

int class_num::class_num_comp(class_num obj, int* error)
{
	UNUSED_PARAMETER(error);
	return 1;
}