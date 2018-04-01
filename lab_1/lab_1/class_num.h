#ifndef CLASS_NUM_H_INCLUDED
#define CLASS_NUM_H_INCLUDED

#define UNUSED_PARAMETER(name) (void)name

#pragma once

class class_num
{
public:
	char name;
	int par_1;
	int par_2;

	class_num();
	class_num(int par_num, class class_num* obj, bool* error);
	~class_num();
	int class_num_comp(class_num obj, bool* error);

private:

};


#endif // CLASS_NUM_H_INCLUDED


