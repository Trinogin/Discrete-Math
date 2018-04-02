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
	if (obj->name == 'u' || obj->name == 'a' || obj->name == 'p'
		|| obj->name == 'c' || obj->name == 's' || obj->name == 'b')
	{
		if (par_num == 1 && obj->name != 'p' && obj->name != 'b')
		{
			*error = true;
			return;
		}
		if(par_num ==2 && (obj->name =='p' || obj->name =='b'))
		{
			*error = true;
			return;
		}
	}
	else
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
	int result = 1;

	switch (obj.name)
	{
	case 'u':
		result = 1;
		// binary pow algorithm
		while (obj.par_2)
		{
			if (obj.par_2 & 1)
			{
				result *= obj.par_1;
				//if (result != 0 && obj.par_1 * result / result == obj.par_1)
				if (obj.par_1 != 0 && result * obj.par_1 / obj.par_1 != result)
				{
					*error = true;
					return 0;
				}
				obj.par_2--;
			}
			else
			{
				obj.par_1 *= obj.par_1;
				obj.par_2 >>= 1;
			}
		}
		break;

	case 'a':

		break;

	case 'p':

		break;

	case 'c':

		break;

	case 's':

		break;

	case 'b':

		break;
	}
	return result;;
}