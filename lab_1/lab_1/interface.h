#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#pragma once

#pragma warning(disable:4996)

#define UNUSED_PARAMETER(name) (void)name

#define UCHAR (unsigned char)

#define MAX_SYM_NUM 11

#define MAX_PARAMS_NUM 4

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include"error.h"
#include"class_num.h"

char* ReadLine(FILE* stream);

void HelpPrint(FILE* stream);

void ParseString(char* string, class_num* my_num_ptr, err_t* error);

void LineParse(char* argv[], class_num* my_num, err_t* error);

#endif // INTERFACE_H_INCLUDED