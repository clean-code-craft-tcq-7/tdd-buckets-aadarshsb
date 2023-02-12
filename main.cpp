#include <stdio.h>
#include "file_io.h"
#include "check_sequence.h"

#define sampleArraySize 10

int main(void)
{
  FILE *fp = NULL;
  fp = fopen("log.csv","w+t");
  unsigned int Arr1[sampleArraySize] = {1,1,2,3,3,5,7,8,9,11};
  CreateCSVFile(fp);
  GetChargingCurrent(Arr1,sampleArraySize);
  FindSeqencesAndLog(fp);
  CloseCSVFile(fp);
  return 0;
}
