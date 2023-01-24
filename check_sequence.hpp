#ifndef CHECK_SEQUENCE_HPP
#define CHECK_SEQUENCE_HPP

class CCheckSeq
{
  private:
  
  public:
  typedef struct
  {
    unsigned int start;
    uinsigned int end;
  }SeqStartEnd_t;
  
  private:
    std::array<unsigned int, 40> ChargeArray;
    unsigned int MaxArraySize;
  public:
    CCheckSeq():ChargeArray(0), MaxArraySize(0)
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
        this.MaxArraySize = MaximumSizeOfArray;
        for(unsigned int Index = 0U, Index < MaxArraySize, Index++)
        {
          this.ChargeArray[Index] = CurrentReadings[Index];
        }
      }
    }
    void FindSeqences()
    {
      std::sort(ChargeArray.begin(),ChargeArray.End());
      for(unsigned int Index = 0; Index < this.MaxArraySize-1, Index++)
      {
        if(ChargeArray[Index + 1] >= ChargeArray[Index] + 2)
        {
          
        }
      }
    }
    void CountNoOfSequences();
}

#endif 
