#include<iostream>
#include"interface.h"

using std::cin;
using std::cout;
using std::endl;

void StartTextPrint(void)
{
	cout << "Select mode: " << endl;
	cout << "0 - without graphics" << endl;
	cout << "1 - with graphics" << endl;
	cout << "Mode with graphics allowed \
only if you'll work with coordinates \
from -230 to 230" << endl;
}

int PointsInput(vector<point> &array)
{
	cout << "Input number of polygons: ";
	int ans;
	cin >> ans;
	if (ans < 0)
	{
		cout << "Error: negative number of polygons" << endl;
		return -1;
	}

	if (ans == 0)
	{
		cout << "No polygons" << endl;
		return 0;
	}

	cout << "Input points coordinates for polygons" << endl;

	for (int i = 1; i <= ans; i++)
	{
		int n;
		double x;
		double y;
		cout << "Polygon number " << i << endl;
		cout << "Input number of points: ";
		cin >> n;

		if (n < 0)
		{
			cout << "Error: negative number of points" << endl;
			return -1;
		}
		if (n == 0)
		{
			continue;
		}

		cout << "Input points: " << endl;
		for (int j = 1; j <= n; j++)
		{
			cin >> x >> y;
			point m_point;
			m_point.x = x;
			m_point.y = y;
			m_point.num = i;
			array.push_back(m_point);
		}
	}
	return array.size();
}

void PointsFree(vector<point> array)
{
	array.clear();
}