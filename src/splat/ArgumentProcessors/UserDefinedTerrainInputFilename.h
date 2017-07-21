#ifndef UserDefinedTerrainInputFilename_h
#define UserDefinedTerrainInputFilename_h

#include "ArgumentProcessor.h"

class Arguments;

class UserDefinedTerrainInputFilename : ArgumentProcessor
{
public:
    UserDefinedTerrainInputFilename(Arguments & arguments, char userDefinedTerrainFilename[]);
    ~UserDefinedTerrainInputFilename();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    char * userDefinedTerrainFilename;
};
#endif
