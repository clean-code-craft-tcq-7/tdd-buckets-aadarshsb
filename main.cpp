#include <stdio.h>
#include "file_io.hpp"
#include "check_sequence.hpp"
#include <array>


int main(void)
{
  FILE *fp;
  const int sampleArraySize = 10;
  unsigned int Arr1[sampleArraySize] = {1,1,2,3,3,5,7,8,9,11};
  
  if(!FileIO::ValFPAndCreateCSVFile(fp))
  {
    printf("Unable to create a file pointer \n");
    return 0;
  }
  CCheckSeq Seq1;
  Seq1.GetChargingCurrent(Arr1, sampleArraySize);
  
  return 0;
}
