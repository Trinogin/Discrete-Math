#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#pragma once

typedef enum
{
	ERR_OK,
	ERR_INCORRECT_STRING,
	ERR_INCORRECT_PARAM
} err_t;

err_t ErrCheck(err_t my_err);

void ErrPrint(err_t my_err);

#endif