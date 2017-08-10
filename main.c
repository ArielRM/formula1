#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

struct formula1 
{
	short season;
	char country[80];
	char driver[80];
	char age;
	char CarNo; //Não utilizado
	char team[80];
	char engine[80];
	char tyres[80];
	char poles[80];
	char wins;
	char podiums;
	char fastestLaps;
	short points;
	char clinched[80];
	char race[80];
	float pointMargin;
};

int main(void)
{
	FILE *input = fopen("formula1.csv","r");
	if(input == NULL)
	{
		perror("Erro ao abrir \"formula1.csv\"");
		exit(EXIT_FAILURE);
	}
	unsigned int records,fieldsPerRecord,maxFieldSize;
	getCSVInfo(input, &records, &fieldsPerRecord, &maxFieldSize);
	
#ifdef DEBUG
printf("This file have:\n\
\t%u records.\n\
Each record have: \n\
\t%u fields.\n\
The longest field have: \n\
\t%u chars(\"\\0\" included).\n",records,fieldsPerRecord,maxFieldSize);
#endif
	struct formula1 F1Array[records-1]; // Retirar a primeira linha
	
	for(unsigned int i = 1; i < records-1; i++)
	{
		for(unsigned int j = 0; j < fieldsPerRecord; j++)
		{
			char buffer[maxFieldSize];
			if(getCSVFieldValue(input, i, j, maxFieldSize, buffer) == NULL)
			{
				printf("Erro durante a leitura do arquivo (%u,%u)",j,i);
				perror("");
				exit(EXIT_FAILURE);
			}
			switch(j)
			{
				case 0:
					sscanf(buffer,"%hd",&F1Array[i-1].season);
					break;
			}
		}
	}
	fclose(input);
}
