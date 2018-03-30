#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#pragma once

#include<iostream>

typedef enum
{
	ERR_OK,
	ERR_INCORRECT_STRING,
	ERR_NOT_ENOUGH_MEM,
} err_t;

void ErrPrint(err_t my_err);

#endif //ERROR_H_INCLUDED