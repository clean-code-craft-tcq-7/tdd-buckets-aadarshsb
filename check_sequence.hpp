#ifndef CHECK_SEQUENCE_HPP
#define CHECK_SEQUENCE_HPP

#include <array>
#include <bits/stdc++.h>
#include "file_io.hpp"

const unsigned int MaximumArraySize = 40U;

class CCheckSeq
{
  private:
  
  public:
  typedef struct
  {
    unsigned int start;
    unsigned int end;
  }SeqStartEnd_t;
  
  private:
    std::array<unsigned int, MaximumArraySize> ChargeArray = {0};
    unsigned int MaxArraySize;
  public:
    CCheckSeq(): MaxArraySize(0)
    {
    }
    void GetChargingCurrent(const unsigned int *CurrentReadings,const unsigned int MaximumSizeOfArray)
    {
      if(MaximumSizeOfArray >= MaximumArraySize) 
      {
        printf("Buffer overflows due to input array size \n");
      }
      else
      {
        this->MaxArraySize = MaximumSizeOfArray;
        for(unsigned int Index = 0U; Index < this->MaxArraySize; Index++)
        {
          this->ChargeArray[Index] = CurrentReadings[Index];
        }
      }
    }
    void FindSeqencesAndLog(FILE* fp) 
    {
      unsigned int StartRange = 0U;
      unsigned int EndRange = 0U;
      unsigned int Counts = 0U;
      std::sort(this->ChargeArray.begin(),this->ChargeArray.end());
      StartRange = this->ChargeArray[0];
      for(unsigned int Index = 0; Index < this->MaxArraySize-1; Index++)
      {
        Counts++;
        if(ChargeArray[Index + 1] >= ChargeArray[Index] + 2)
        {
          SeqStartEnd_t SeqStartEnd = {0};
          EndRange = this->ChargeArray[Index];
          SeqStartEnd.start = StartRange;
          StartRange.end = EndRange;
          //Call the file IO operation 
          FileIO::WriteDataToLine(fp, &StartRange, Counts);
          
          Counts = 0U; 
          StartRange = this->ChargeArray[Index + 1];
        }
      }
    }
};

#endif 
