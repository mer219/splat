#include "TopographicMapOutputFilename.h"

#include <cstring>
#include <stdexcept>

TopographicMapOutputFilename::TopographicMapOutputFilename(char mapfile[], bool & generateTopographicalMap) :
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

bool TopographicMapOutputFilename::DoesThisOptionTakeAValue()
{
    return true;
}
    
void TopographicMapOutputFilename::ProcessArgument(const char argument[])
{
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
