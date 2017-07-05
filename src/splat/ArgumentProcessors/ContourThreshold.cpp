#include "ContourThreshold.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

ContourThreshold::ContourThreshold(int& contourThreshold) :
    contourThreshold(contourThreshold)
{
}

ContourThreshold::~ContourThreshold()
{
}

bool ContourThreshold::ArgumentBelongsToThisProcessor(const char * argument)
{
    return (strcmp(argument, "-db") == 0 || strcmp(argument, "-dB") == 0);
}

bool ContourThreshold::DoesThisOptionTakeAValue()
{
    return true;
}
    
void ContourThreshold::ProcessArgument(const char argument[])
{
    if (argument[0])
    {
        sscanf(argument, "%d", &contourThreshold);
    }
    else
    {
        throw std::invalid_argument("Invalid Range Value");
    }
}
