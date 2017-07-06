#ifndef SplatDataFilePath_h
#define SplatDataFilePath_h

#include "ArgumentProcessor.h"

class SplatDataFilePath : ArgumentProcessor
{
public:
    SplatDataFilePath(char * splatDataFilePath);
    ~SplatDataFilePath();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    char * splatDataFilePath;
};
#endif
