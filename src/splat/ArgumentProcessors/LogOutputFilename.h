#ifndef LogOutputFilename_h
#define LogOutputFilename_h

#include "ArgumentProcessor.h"

class Arguments;

class LogOutputFilename : ArgumentProcessor
{
public:
    LogOutputFilename(Arguments & arguments, char * logFile, bool & logOutputToFile);
    ~LogOutputFilename();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    char * logFile;
    bool & logOutputToFile;
};
#endif
