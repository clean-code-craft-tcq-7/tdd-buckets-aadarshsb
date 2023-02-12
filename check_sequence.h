#ifndef CHECK_SEQUENCE_H
#define CHECK_SEQUENCE_H

#include <stdlib.h>
#include <stdio.h>
#include "file_io.h"

//fn declaration 
//public methods
void GetChargingCurrent(const unsigned int *CurrentReadings,const unsigned int MaxSizeOfInputArray);
void FindSeqencesAndLog(FILE* fp);


#endif 
