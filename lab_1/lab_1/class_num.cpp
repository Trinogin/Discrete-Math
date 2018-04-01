#include "class_num.h"
#include<limits>

class_num::class_num()
{
	this->name = '0';
	this->par_1 = 0;
	this->par_2 = 0;
}

class_num::class_num(int par_num, class class_num* obj, bool* error)
{
	if (obj->name != 'u' && obj->name != 'a' && obj->name != 'p'
		&& obj->name != 'c' && obj->name != 's' && obj->name != 'b')
	{
		*error = true;
		return;
	}
}

class_num::~class_num()
{
}

int class_num::class_num_comp(class_num obj, bool* error)
{
	UNUSED_PARAMETER(error);
	return INT_MAX;
}