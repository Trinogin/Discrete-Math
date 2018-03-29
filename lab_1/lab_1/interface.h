#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#define UNUSED_PARAMETER(name) (void)name

#pragma once

#pragma warning(disable:4996)

#include<iostream>
#include<cstdlib>
#include"error.h"
#include"class_num.h"

char* ReadLine(FILE* stream);

void ParseString(char* string, class_num* my_num, err_t* error);

void HelpPrint(FILE* stream);

#endif // INTERFACE_H_INCLUDED