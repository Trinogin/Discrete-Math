#ifndef INTERFACE_H_INCLUDED

#define INTERFACE_H_INCLUDED

#pragma once

#include<vector>

#define UNUSED_PARAMETER(a) (void)a

using std::vector;

struct point
{
	double x;
	double y;
	int num;
};

void StartTextPrint(void);

// ������� ���������� ���-�� ��������� �����, -1 == ������
int PointsInput(vector<point> &array);

void PointsFree(vector<point> array);

#endif // !INTERFACE_H_INCLUDED



