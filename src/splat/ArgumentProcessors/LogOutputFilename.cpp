#include "LogOutputFilename.h"

#include "Arguments.h"

#include <cstring>
#include <stdexcept>

LogOutputFilename::LogOutputFilename(Arguments & arguments, char * logFile, bool & logOutputToFile) :
    arguments(arguments),
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

void LogOutputFilename::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
        if (argument[0] && argument[0] != '-')
        {
            strncpy(logFile, argument, 253);
            logOutputToFile = true;
        }
        else
        {
            throw std::invalid_argument("Invalid Log File Name");
        }
    }
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
