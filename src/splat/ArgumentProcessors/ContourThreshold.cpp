#include "ContourThreshold.h"

#include "Arguments.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

ContourThreshold::ContourThreshold(Arguments & arguments, int & contourThreshold) :
    arguments(arguments),
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

void ContourThreshold::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();

        if (argument[0])
        {
            sscanf(argument, "%d", &contourThreshold);
        }
        else
        {
            throw std::invalid_argument("Invalid Contour Threshold Value");
        }
    }
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
