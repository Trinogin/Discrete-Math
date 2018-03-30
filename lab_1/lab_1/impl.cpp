#include"impl.h"

void HelpPrint(FILE* stream)
{
	char* str;
	int ch;
	FILE* file;
	int i = 0;

	file = fopen("HelpFile.txt", "r");
	if (file == NULL)
	{
		fprintf(stream, "Error with help \n");
		return;
	}
	while ((ch = getc(file)) != EOF)
		i++;

	fseek(file, SEEK_SET, 0);

	str = (char*)malloc((i + 1) * sizeof(char));
	if (str == NULL)
	{
		fprintf(stream, "Error with help \n");
		fclose(file);
		return;
	}

	fread(str, sizeof(char), i, file);
	str[i] = '\0';

	fprintf(stream, "%s \n", str);

	free(str);
	fclose(file);
}

void SpaceSkip(char* str)
{

}
