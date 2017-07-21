#include "SplatDataFilePath.h"

#include "Arguments.h"

#include <cstring>
#include <stdexcept>

SplatDataFilePath::SplatDataFilePath(Arguments & arguments, char * splatDataFilePath) :
    arguments(arguments),
    splatDataFilePath(splatDataFilePath)
{
}

SplatDataFilePath::~SplatDataFilePath()
{
}

bool SplatDataFilePath::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-sdf") == 0;
}

void SplatDataFilePath::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
        if (argument[0] && argument[0] != '-')
        {
            strncpy(splatDataFilePath, argument, 253);
        }
        else
        {
            throw std::invalid_argument("Invalid Splat Data File Path");
        }
    }
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
