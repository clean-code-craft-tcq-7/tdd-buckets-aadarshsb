#ifndef TESTFILE_HPP
#define TESTFILE_HPP

#include "file_io.hpp"
#include <assert.h>

class FileIOStub:class FileIO
{
  private:
  public:
    virtual static bool ValFPAndCreateCSVFile(FILE *fp) override
    {
      assert(fp != NULL); 
    }
    static void CloseFile(FILE *fp) override
    {
      //Dummy Stub
      assert(fp != NULL);
    }
    static void WriteDataToLine(FILE* fp,const CCheckSeq::SeqStartEnd_t& SeqStarEnd,const unsigned int count) override
    {
      //Dummy stub
      assert(TRUE);
    }
}

#endif