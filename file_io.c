#include "file_io.h"

unsigned char CreateCSVFile(FILE* fp)
{
  if(fp == NULL)
  {
    printf("File pointer can't be created \n");
    return 0;
  }
  else
  {
    fputs("Range,Readings\n",fp);
    return 1;
  }
}

void CloseCSVFile(FILE *fp)
{
  fclose(fp);
}

void WriteSetOfDataToCSV(FILE* fp,const SeqStartEnd_t *SeqStarEnd,const unsigned int count)
{
  //Strings to convert the int value to string
  char Range[30]={"\0"};
  //Int -> String
  sprintf(Range,"%d - %d,%d\n",SeqStarEnd->start, SeqStarEnd->end, count);
  fputs(Range,fp);
}
