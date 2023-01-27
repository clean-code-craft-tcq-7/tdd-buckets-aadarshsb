#ifndef FILE_IO_HPP
#define FILE_IO_HPP

#include<array>
#include<string>
#include "check_sequence.hpp"

using namespace std;

class FileIO
{
  private:
  public:
    virual bool ValFPAndCreateCSVFile(FILE *fp)
    {
      fp = fopen("log.csv","w+t"); 
      if(fp== NULL)
      {
        printf("File pointer can't be created \n");
        return 0;
      }
      else
      {
        printf("File created Successfully \n");
        fputs("Range  Readings \n",fp);
        return 1;
      }
    }
    virtual void CloseFile(FILE *fp)
    {
      fclose(fp);
    }
    virtual void WriteDataToLine(FILE* fp,const CCheckSeq::SeqStartEnd_t& SeqStarEnd,const unsigned int count)
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

class FileIOStub: private FileIO
{
  private:
  public:
    virtual bool ValFPAndCreateCSVFile(FILE *fp) override
    {
      assert(fp != NULL); 
    }
    virtual void CloseFile(FILE *fp) override
    {
      //Dummy Stub
      assert(fp != NULL);
    }
    virtual void WriteDataToLine(FILE* fp,const CCheckSeq::SeqStartEnd_t& SeqStarEnd,const unsigned int count) override
    {
      //Dummy stub
      assert(TRUE);
    }
};

#endif
