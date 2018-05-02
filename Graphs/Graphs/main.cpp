#include<iostream>
#include<vld.h>
#include<vector>

#include"interface.h"
#include"graph.h"
#include"labengine.h"
#include"MyDraw.h"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	StartTextPrint();

	int ans;
	cin >> ans;
	if (ans)
	{
		if (LabInit())
		{
			vector<point> array;
			int point_num = PointsInput(array);
			if (point_num == -1)
			{
				PointsFree(array);
				LabTerm();
				return -1;
			}


			int width = LabGetWidth();
			int height = LabGetHeight();

			DrawPolygons(array);

			LabDrawFlush();
			LabInputKey();
			LabTerm();
			PointsFree(array);
		}
	}
	else
	{
		vector<point> array;
		int point_num = PointsInput(array);
		if (point_num == -1)
		{
			PointsFree(array);
			return -1;
		}
		PointsFree(array);
	}

	return 0;
}