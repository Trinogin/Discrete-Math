#include "class_num.h"
#include "computing.h"
#include <cstdio>

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

	switch (obj.name)
	{
	case 'u':
		result = Num_of_placements(obj.par_1, obj.par_2, error);
		break;

	case 'a': 
		result = Num_of_placements_wr(obj.par_1, obj.par_2, error);
		break;

	case 'p':
		result = Num_of_permutations(obj.par_1, error);
		break;

	case 'c':
		result = Num_of_combinations(obj.par_1, obj.par_2, error);
		break;

	case 's':
		result = Stirlings_number(obj.par_1, obj.par_2, error);
		break;

	case 'b':
		result = Bells_number(obj.par_1, error);
		break;
	}
	return result;
}