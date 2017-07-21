#include "TopographicMapOutputFilename.h"

#include "Arguments.h"

#include <cstring>
#include <stdexcept>

TopographicMapOutputFilename::TopographicMapOutputFilename(Arguments & arguments, char mapfile[], bool & generateTopographicalMap) :
    arguments(arguments),
    mapFile(mapFile),
    generateTopographicalMap(generateTopographicalMap)
{
}

TopographicMapOutputFilename::~TopographicMapOutputFilename()
{
}

bool TopographicMapOutputFilename::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-o") == 0;
}

void TopographicMapOutputFilename::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();

        if (argument[0] && argument[0] != '-')
        {
            strncpy(mapFile, argument, 253);
            generateTopographicalMap = true;
        }
        else
        {
            throw std::invalid_argument("Invalid Topographic Map Output Filename");
        }
    }
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
