#ifndef FILE_IO_HPP
#define FILE_IO_HPP

#include<array>
#include<string>
#include "check_sequence.hpp"

using namespace std;

class FileIO
{
  private:
    static void CreateNewFile(FILE* fp)
    {
      
    }
  public:
    static bool ValFPAndCreateCSVFile(FILE *fp)
    {
      if(fp == NULL)
      {
        printf("File pointer can't be created");
        return 0;
      }
      else
      {
        fp = fopen("log.csv","rw");
        printf("File created Successfully");
        fputs("Range  Readings \n",fp);
        return 1;
      }
    }
    static void CloseFile(FILE *fp)
    {
      fclose(fp);
    }
    static void WriteDataToLine(FILE* fp,const CCheckSeq::SeqStartEnd_t& SeqStarEnd,const unsigned int count)
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
};

#endif
