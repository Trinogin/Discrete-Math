#include"impl.h"



int SpaceSkip(char* str, int i)
{
	while (isspace((unsigned char)str[i]) && str[i] != '\0')
		i++;
	return i;
}
