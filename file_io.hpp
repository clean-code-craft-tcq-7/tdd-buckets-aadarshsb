#ifndef FILE_IO_HPP
#define FILE_IO_HPP

#include<array>
#include<string>

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
        fp = f.open("log.csv","rw");
        printf("File created Successfully");
        fputs("Range  Readings \n",this.fp);
      }
    }
  
    void CloseFile(void) const
    {
      fclose(fp);
    }
    
    void WriteDataToLine(const char& SeqStartEnd_t,const unsigned int count) const
    {
      std::array<std::string, 20> Range = {"\0"};
      std::array<std::string, 8> Reading = {"\0"};
      sprintf(Range,"%d - %d",SeqStartEnd_t.start, SeqStartEnd_t.end);
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
