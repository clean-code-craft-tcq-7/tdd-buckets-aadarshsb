#ifndef FILE_IO_HPP
#define FILE_IO_HPP

#include<array>
#include<string>
#include "check_sequence.hpp"

using namespace std;

class FileIO
{
  private:
    FILE *fp;
  public:
    FileIO()
    {
      if(fp == NULL)
      {
        printf("File pointer can't be created");
      }
      else
      {
        fp = fopen("log.csv","rw");
        printf("File created Successfully");
        fputs("Range  Readings \n",fp);
      }
    }
  
    void CloseFile(void) const
    {
      fclose(fp);
    }
    
    void WriteDataToLine(SeqStartEnd_t& SeqStarEnd,const unsigned int count) const
    {
      char Range[20]={"\0"};
      char Reading[8]={"\0"};
      //std::array<std::string, 20> Range = {"\0"};
      //std::array<std::string, 8> Reading = {"\0"};
      sprintf(Range,"%d - %d",SeqStarEnd.start, SeqStarEnd.end);
      fputs(Range,fp);
      sprintf(Reading,"%d\n",count);
      fputs(Reading,fp);
    }
    
    ~FileIO()
    {
      fclose(fp);
      fp = NULL;
    }
};

#endif
