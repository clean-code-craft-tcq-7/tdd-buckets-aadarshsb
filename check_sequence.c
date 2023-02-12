#include "check_sequence.h"

//constants 
#define sc_ui32MaximumArraySize 40U

//static variables 
static unsigned int s_ui32ChargeArray[sc_ui32MaximumArraySize] = {0};
static unsigned int s_ui32SizeOfCurrentArray;

//private method prototypes
static void QuickSortArray(void);
static int cmpfunc (const void * a, const void * b);


void GetChargingCurrent(const unsigned int *CurrentReadings,const unsigned int MaxSizeOfInputArray)
{
    if(MaxSizeOfInputArray >= sc_ui32MaximumArraySize) 
    {
      printf("Buffer overflows due to input array size \n");
    }
    else
    {
      s_ui32SizeOfCurrentArray = MaxSizeOfInputArray;
      for(unsigned char ui8Index = 0U; ui8Index < s_ui32SizeOfCurrentArray; ui8Index++)
      {
      	//Copy the array, so that, post the array can be sorted and go through further checks
        s_ui32ChargeArray[ui8Index] = CurrentReadings[ui8Index];
      }
    }
}

void QuickSortArray(void)
{
  qsort((void*)s_ui32ChargeArray, s_ui32SizeOfCurrentArray , sizeof(unsigned int), cmpfunc);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(unsigned int*)a - *(unsigned int*)b );
}

void FindSeqencesAndLog(FILE* fp) 
{
  unsigned int StartRange = 0U;
  unsigned int EndRange = 0U;
  unsigned int Counts = 0U;
  
  QuickSortArray();
  
  StartRange = s_ui32ChargeArray[0];
  for(unsigned char ui8Index = 0; ui8Index < s_ui32SizeOfCurrentArray-1; ui8Index++)
  {
    Counts++;
    //Marks the end of a sequence
    if(s_ui32ChargeArray[ui8Index + 1] >= (s_ui32ChargeArray[ui8Index] + 2) ) //Reason is that, if there is discon. there must be atleast 2 increment in number
    {
      SeqStartEnd_t SeqStartEnd;
      EndRange = s_ui32ChargeArray[ui8Index];
      SeqStartEnd.start = StartRange;
      SeqStartEnd.end = EndRange;
      //Call the file IO operation 
      WriteSetOfDataToCSV(fp, &SeqStartEnd, Counts);
      //After logging the data, reset the count and set the next start point as next array element 
      Counts = 0U; 
      StartRange = s_ui32ChargeArray[ui8Index + 1];
    }
  }
}
