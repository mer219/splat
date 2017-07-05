#include "UserDefinedTerrainInputFilename.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

UserDefinedTerrainInputFilename::UserDefinedTerrainInputFilename(char userDefinedTerrainFilename[]) :
    userDefinedTerrainFilename(userDefinedTerrainFilename)
{
}

UserDefinedTerrainInputFilename::~UserDefinedTerrainInputFilename()
{
}

bool UserDefinedTerrainInputFilename::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-udt") == 0;
}

bool UserDefinedTerrainInputFilename::DoesThisOptionTakeAValue()
{
    return true;
}
    
void UserDefinedTerrainInputFilename::ProcessArgument(const char argument[])
{
    if (argument[0] && argument[0] != '-')
    {
        strncpy(userDefinedTerrainFilename, argument, 253);
    }
    else
    {
        throw std::invalid_argument("Invalid Range Value");
    }
}
