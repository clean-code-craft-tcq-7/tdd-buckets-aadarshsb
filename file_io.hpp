#ifndef FILE_IO_HPP
#define FILE_IO_HPP

using namespace std;

class FileIO
{
  private:
    FILE *fp;
  public:
    FileIO()
    {
      if(this.fp == NULL)
      {
        printf("File pointer can't be created");
      }
      else
      {
        this.fp = f.open("log.csv","rw");
        printf("File created Successfully");
        fputs("Range  Readings \n",this.fp);
      }
    }
  
    void CloseFile(void) const
    {
      fclose(this.fp);
    }
    
    void WriteDataToLine(const char& SeqStartEnd_t,const unsigned int count) const
    {
      std::array<std::string, 20> Range = {"\0"};
      std::array<std::string, 8> Reading = {"\0"};
      sprintf(Range,"%d - %d",SeqStartEnd_t.start, SeqStartEnd_t.end);
      fputs(Range, this.fp);
      sprintf(Reading,"%d\n",count);
      fputs(Reading,this.fp);
    }
    
    ~FileIO()
    {
      fclose(this.fp);
      this.fp = NULL;
    }
};

#endif
