#ifndef CLASS_NUM_H_INCLUDED
#define CLASS_NUM_H_INCLUDED

#pragma once

class class_num
{
public:
	char name;
	int par_1;
	int par_2;

	class_num(int par_num, char ch, int par_1, int par_2);
	~class_num();
	int class_num_comp(class_num obj, int* error);

private:

};


#endif // CLASS_NUM_H_INCLUDED


