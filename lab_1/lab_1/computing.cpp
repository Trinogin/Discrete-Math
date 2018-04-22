#include"computing.h"

// binary pow algorithm
unsigned int Num_of_placements(unsigned int num, unsigned int deg, bool* error)
{
	unsigned int result = 1;
	while (deg)
	{
		if (deg& 1)
			if ((num != 0) && ((result * num) / num != result))
			{
				*error = true;
				return 0;
			}
			else
				result *= num;
		if ((num != 0) && ((num * num) / num != num) && (deg > 1))
		{
			*error = true;
			return 0;
		}
		else
		{
			num *= num;
			deg >>= 1;
		}
	}
	return result;
}

unsigned int Num_of_placements_wr(unsigned int m, unsigned int n, bool* error)
{
	unsigned int result = 1;
	unsigned int interm;

	if (n > m)
		return 0;
	if (n == 0)
		return 1;
	interm = m - n + 1;
	result = interm;
	while (interm < m)
	{
		interm++;
		if (interm != 0 && result * interm / interm != result)
		{
			*error = true;
			return 0;
		}
		result *= interm;
	}
	return result;
}

unsigned int Num_of_permutations(unsigned int num, bool* error)
{
	unsigned int result = 1;
	for (unsigned int i = num; i > 0; i--)
	{
		if (result * i / i != result)
		{
			*error = true;
			return 0;
		}
		result *= i;
	}
	return result;
}

unsigned int Num_of_combinations(unsigned int m, unsigned int n, bool* error)
{
	unsigned int result;
	unsigned int* array;

	if (n > m)
		return 0;
	if (m == n)
		return 1;
	if (n == 1 || m == n + 1)
		return m;
	if (n > m - n)
		n = m - n;
	if (n == 0)
		return 1;

	try 
	{
		if (n + 1 < n || n + 1 < 1)
		{
			*error = true;
			return 0;
		}
		array = new unsigned int[n + 1];
	}
	catch(...)
	{
		*error = true;
		return 0;
	}

	for (unsigned int i = 0; i <= n; i++)
		array[i] = 1;

	for (unsigned int i = 1; i <= m - n; i++)
		for (unsigned int j = 1; j <= n; j++)
			if (array[j] + array[j - 1] < array[j] || array[j] + array[j - 1] < array[j - 1])
			{
				*error = true;
				return 0;
			}
			else
				array[j] = array[j] + array[j - 1];

	result = array[n];
	delete[] array;
	return result;
}

unsigned int Stirlings_number(unsigned int m, unsigned int n, bool* error)
{
	unsigned int result = 1;
	unsigned int* array = nullptr;
	unsigned int i;
	unsigned int j;

	if (m == n)
		return 1;
	if (n == 0)
		return 0;
	if (n > m)
		return 0;
	if (n == 1)
		return 1;
	
	try
	{
		if (n + 1 < n || n + 1 < 1)
		{
			*error = true;
			return 0;
		}
		array = new unsigned int[n + 1];
	}
	catch (...)
	{
		*error = true;
		return 0;
	}

	for (i = 1; i <= n; i++)
		array[i] = 1;
	
	for (i = 1; i <= m - n; i++)
		for (j = 2; j <= n; j++)
			if (j * array[j] + array[j - 1] <= array[j] || j * array[j] + array[j - 1] <= array[j - 1])
			{
				*error = true;
				delete[] array;
				return 0;
			}
			else
				array[j] = array[j - 1] + j * array[j];
	result = array[n];
	delete[] array;
	return result;
}

unsigned int Bells_number(unsigned int m, bool* error)
{
	unsigned int result = 1;
	unsigned int* array;
	unsigned int n;
	unsigned int s;
	unsigned int k;
	unsigned int t;

	if (m == 0)
		return 1;

	try 
	{
		if (m + 1 < m || m + 1 < 1)
		{
			*error = true;
			return 0;
		}
		array = new unsigned int[m + 1];
	}
	catch (...)
	{
		*error = true;
		return 0;
	}
	
	array[1] = 1;

	for (n = 2; n <= m; n++ )
	{
		t = array[1];
		array[1] = array[n - 1];

		for (k = 2; k <= n; k++)
		{
			s = array[k];
			if (array[k - 1] + t < array[k - 1] || array[k - 1] + t < t)
			{
				*error = true;
				delete[] array;
				return 0;
			}
			else
			{
				array[k] = array[k - 1] + t;
				t = s;
			}
		}
	}
	result = array[m];
	delete[] array;
	return result;
}