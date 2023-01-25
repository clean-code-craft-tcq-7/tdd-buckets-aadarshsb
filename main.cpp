#include <stdio.h>
#include "file_io.hpp"

int main(void)
{
  FILE *fp = NULL;
  if(!FileIO::ValFPAndCreateCSVFile(fp))
  {
    printf("Unable to create a file pointer \n");
    return 0;
  }
  
  return 0;
}
