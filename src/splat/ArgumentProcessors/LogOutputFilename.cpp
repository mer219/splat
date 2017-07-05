#include "LogOutputFilename.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

LogOutputFilename::LogOutputFilename(char* logFile, bool& logOutputToFile) :
    logFile(logFile),
    logOutputToFile(logOutputToFile)
{
}

LogOutputFilename::~LogOutputFilename()
{
}

bool LogOutputFilename::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-log") == 0;
}

bool LogOutputFilename::DoesThisOptionTakeAValue()
{
    return true;
}
    
void LogOutputFilename::ProcessArgument(const char argument[])
{
    if (argument[0] && argument[0] != '-')
    {
        strncpy(logFile, argument, 253);
        logOutputToFile = true;
    }
    else
    {
        throw std::invalid_argument("Invalid Log Filename");
    }
}
