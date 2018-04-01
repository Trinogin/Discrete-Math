#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#define UNUSED_PARAMETER(name) (void)name

#define UCHAR (unsigned char)

#pragma once

#pragma warning(disable:4996)

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include"error.h"
#include"class_num.h"

char* ReadLine(FILE* stream);

void HelpPrint(FILE* stream);

void ParseString(char* string, class_num* my_num, err_t* error);

void LineParse(char* argv[], class_num* my_num, err_t* error);

#endif // INTERFACE_H_INCLUDED