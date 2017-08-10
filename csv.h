#ifndef CSV_H_INCLUDED
#define CSV_H_INCLUDED
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "csv.h"
char* getCSVFieldValue(FILE *file, unsigned int record, unsigned int field, unsigned int maxValue, char *str);
void getCSVInfo(FILE *file,unsigned int *records, unsigned int *fieldPerRecord, unsigned int *maxFieldSize);
#endif
