#ifndef CHECK_SEQUENCE_HPP
#define CHECK_SEQUENCE_HPP

#include <array>

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
    std::array<unsigned int, 40> ChargeArray = {0};
    unsigned int MaxArraySize;
  public:
    CCheckSeq(): MaxArraySize(0)
    {
    }
    void GetChargingCurrent(const unsigned int& CurrentReadings,const unsigned int MaximumSizeOfArray) const
    {
      if(MaximumSizeOfArray >= 40) 
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
    void FindSeqences()
    {
      unsigned int StartRange = 0U;
      unsigned int EndRange = 0U;
      unsigned int Counts = 0U;
      std::qsort(this->ChargeArray.begin(),this->ChargeArray.End());
      StartRange = this->ChargeArray[0];
      for(unsigned int Index = 0; Index < this->MaxArraySize-1; Index++)
      {
        Counts++;
        if(ChargeArray[Index + 1] >= ChargeArray[Index] + 2)
        {
          EndRange = this->ChargeArray[Index];
          //Call the file IO operation 
          
          Count = 0; 
          StartRange = this->ChargeArray[Index + 1];
        }
      }
    }
};

#endif 
