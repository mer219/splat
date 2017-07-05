#ifndef LogOutputFilename_h
#define LogOutputFilename_h

#include "ArgumentProcessor.h"

class LogOutputFilename : ArgumentProcessor
{
public:
    LogOutputFilename(char* logFile, bool& logOutputToFile);
    ~LogOutputFilename();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    char* logFile;
    bool& logOutputToFile;
};
#endif
