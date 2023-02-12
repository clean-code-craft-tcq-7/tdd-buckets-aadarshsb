#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>
#include "check_sequence.h"


typedef struct _SeqStartEnd
{
  unsigned int start;
  unsigned int end;
}SeqStartEnd_t;

//fn declaration 


//public
unsigned char CreateCSVFile(FILE* fp);
void CloseCSVFile(FILE *fp);
void WriteSetOfDataToCSV(FILE* fp,const SeqStartEnd_t *SeqStarEnd,const unsigned int count);

#endif
