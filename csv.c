#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

int getCSVFieldValue(FILE *file, unsigned int record, unsigned int field, unsigned int maxValue, char *buffer)
{
	for(unsigned int i = 0; i < record; i++)
	{
		if(fscanf(file,"%*[^\n]s\n")!=0)
			return(-1);
	}
	for(unsigned int i = 0; i < field; i++)
	{
		if(fscanf(file,"%*[^\n;]s%*[;\n]c")!=0)
			return(-2);
	}
	unsigned int i = 0;
	for(i = 0; i < maxValue; i++)
	{
		if(fscanf(file,"%[^;\n]c",&(buffer[i])) != 1)
		{
			buffer[i] = '\0';
			break;
		}
	}
	return(i);
}
