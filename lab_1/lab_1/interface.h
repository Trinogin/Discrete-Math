#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#define UNUSED_PARAMETER(name) (void)name

#pragma once

#include<iostream>
#include<cstdlib>
#include"error.h"
#include"class_num.h"

char* ReadLine(FILE* stream);

void ParseString(char* string, class_num* my_num, err_t* error);

#endif // INTERFACE_H_INCLUDED