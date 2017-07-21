#ifndef SplatDataFilePath_h
#define SplatDataFilePath_h

#include "ArgumentProcessor.h"

class Arguments;

class SplatDataFilePath : ArgumentProcessor
{
public:
    SplatDataFilePath(Arguments & arguments, char * splatDataFilePath);
    ~SplatDataFilePath();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    char * splatDataFilePath;
};
#endif
