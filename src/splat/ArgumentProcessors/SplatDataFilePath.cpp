#include "SplatDataFilePath.h"

#include <cstring>
#include <stdexcept>

SplatDataFilePath::SplatDataFilePath(char * splatDataFilePath) :
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

bool SplatDataFilePath::DoesThisOptionTakeAValue()
{
    return true;
}
    
void SplatDataFilePath::ProcessArgument(const char argument[])
{
    if (argument[0] && argument[0] != '-')
    {
        strncpy(splatDataFilePath, argument, 253);
    }
    else
    {
        throw std::invalid_argument("Invalid Splat Data File Path");
    }
}
