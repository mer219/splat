#include "UserDefinedTerrainInputFilename.h"

#include "Arguments.h"

#include <cstring>
#include <stdexcept>

UserDefinedTerrainInputFilename::UserDefinedTerrainInputFilename(Arguments & arguments, char userDefinedTerrainFilename[]) :
    arguments(arguments),
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

void UserDefinedTerrainInputFilename::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
        if (argument[0] && argument[0] != '-')
        {
            strncpy(userDefinedTerrainFilename, argument, 253);
        }
        else
        {
            throw std::invalid_argument("Invalid User Define Terrain Input File Name");
        }
    }
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
