#ifndef COMPUTING_H_INCLUDED

#define COMPUTING_H_INCLUDED

#include<cstdlib>

#pragma once

unsigned int Num_of_placements(unsigned int num, unsigned int deg, bool* error);

unsigned int Num_of_placements_wr(unsigned int num, unsigned int deg, bool* error);

unsigned int Num_of_permutations(unsigned int num, bool* error);

unsigned int Num_of_combinations(unsigned int m, unsigned int n, bool* error);

unsigned int Stirlings_number(unsigned int m, unsigned int n, bool* error);

unsigned int Bells_number(unsigned int m,bool* error);

#endif // !COMPUTING_H_INCLUDED