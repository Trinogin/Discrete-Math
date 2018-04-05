#include "class_num.h"

#include<cstdio>

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

unsigned int class_num::class_num_comp(class_num obj, bool* error)
{
	unsigned int result = 1;
	unsigned int interm;
	unsigned int* array = NULL;
	switch (obj.name)
	{
	case 'u': // ended
		result = 1;
		// binary pow algorithm
		while (obj.par_2)
		{
			if (obj.par_2 & 1)
				if ((obj.par_1 != 0) && ((result * obj.par_1) / obj.par_1 != result))
				{
					*error = true;
					return 0;
				}
				else
					result *= obj.par_1;
			if ((obj.par_1 != 0) && ((obj.par_1 * obj.par_1) / obj.par_1 != obj.par_1) && (obj.par_2 > 1))
			{
				*error = true;
				return 0;
			}
			else
			{
				obj.par_1 *= obj.par_1;
				obj.par_2 >>= 1;
			}
		}
		break;
//---------------------------------------------------------
	case 'a': // ended
		if (obj.par_2 > obj.par_1)
			return 0;
		if (obj.par_2 == 0)
			return 1;
		interm = obj.par_1 - obj.par_2 + 1;
		result = interm;
		while (interm < obj.par_1)
		{
			interm++;
			if (interm != 0 && result * interm / interm != result)
			{
				*error = true;
				return 0;
			}
			result *= interm;
		}
		break;
//---------------------------------------------------------
	case 'p': // ended
		result = 1;
		for (unsigned int i = obj.par_1; i > 0; i--)
		{
			if (result * i / i != result)
			{
				*error = true;
				return 0;
			}
			result *= i;
		}
		break;
//---------------------------------------------------------
	case 'c':
		if (obj.par_2 > obj.par_1)
			return 0;
		if (obj.par_1 == obj.par_2)
			return 1;
		if (obj.par_2 == 1 || obj.par_1 == obj.par_2 + 1)
			return obj.par_1;
		if (obj.par_2 > obj.par_1 - obj.par_2)
			obj.par_2 = obj.par_1 - obj.par_2;
		if (obj.par_2 == 0)
			return 1;

		array = new unsigned int[obj.par_2 + 1];

		for (unsigned int i = 0; i <= obj.par_2; i++)
			array[i] = 1;

		for (unsigned int i = 1; i <= obj.par_1 - obj.par_2; i++)
			for (unsigned int j = 1; j <= obj.par_2; j++)
				if (array[j] + array[j - 1] < array[j] || array[j] + array[j - 1] < array[j - 1])
				{
					*error = true;
					return 0;
				}
				else
					array[j] = array[j] + array[j - 1];

		result = array[obj.par_2];
		delete[] array;
		break;
//---------------------------------------------------------
	case 's':

		break;
//---------------------------------------------------------
	case 'b':

		break;
	}
	return result;
}