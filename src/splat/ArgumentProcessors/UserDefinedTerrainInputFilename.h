#ifndef UserDefinedTerrainInputFilename_h
#define UserDefinedTerrainInputFilename_h

#include "ArgumentProcessor.h"

class UserDefinedTerrainInputFilename : ArgumentProcessor
{
public:
    UserDefinedTerrainInputFilename(char userDefinedTerrainFilename[]);
    ~UserDefinedTerrainInputFilename();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    char* userDefinedTerrainFilename;
};
#endif
