#include"MyDraw.h"

void DrawPolygons(vector<point> &array)
{
	if (array.size() == 0)
		return;

	int n;
	LabSetColor(LABCOLOR_RED);
	for (unsigned int i = 0; i < array.size() -1 ; i++)
	{
		n = i;
		while (i < array.size() - 1 && array[i].num == array[i + 1].num )
		{
			LabDrawLine((int)array[i].x,(int) array[i].y,(int) array[i + 1].x,(int) array[i + 1].y);
			i++;
		}
		LabDrawLine((int)array[i].x, (int)array[i].y, (int)array[n].x, (int)array[n].y);
	}
}