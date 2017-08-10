#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

char* getCSVFieldValue(FILE *file, unsigned int record, unsigned int field, unsigned int maxValueSize, char *str)
{
	for(unsigned int i = 0; i < record; i++)
	{
		if(fscanf(file,"%*[^\n]s")!=0)
			return(NULL);
		fgetc(file);
	}
	for(unsigned int i = 0; i < field; i++)
	{
		if(fscanf(file,"%*[^\n;]s;")!=0)
			return(NULL);
		fgetc(file);
	}
	char buffer[maxValueSize];
	fgets(buffer,maxValueSize,file);
	rewind(file);
	if(sscanf(buffer,"%[^;\n]s",str) != 1)
		return(NULL);
	return(str);
}
void getCSVInfo(FILE *file,unsigned int *records, unsigned int *fieldPerRecord, unsigned int *maxFieldSize) 
{
	*records = 0;
	*fieldPerRecord = 0;
	*maxFieldSize = 0;
	
	unsigned int currentFieldSize = 0;
	char hold;
	while(fscanf(file,"%c",&hold) == 1)
	{
		if(hold == ';' || hold == '\n')
		{
			currentFieldSize++;
			if(*records == 0)
				(*fieldPerRecord)++;
			if(hold == '\n')
				(*records)++;
			if(currentFieldSize > *maxFieldSize)
				*maxFieldSize = currentFieldSize;
			currentFieldSize = 0;
		}
		else
			currentFieldSize++;
	}
	rewind(file);
}
	
