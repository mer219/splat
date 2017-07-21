#include "RangeModifier.h"

#include "Arguments.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

RangeModifier::RangeModifier(Arguments & arguments, double & maxRange) :
    arguments(arguments),
    maxRange(maxRange)
{
}

RangeModifier::~RangeModifier()
{
}

bool RangeModifier::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-R") == 0;
}

void RangeModifier::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
        if (argument[0] && argument[0] != '-')
        {
            sscanf(argument, "%lf", &maxRange);
            
            if (maxRange < 0.0)
	        {
                maxRange = 0.0;
	        }
	        else if (maxRange > 1000.0)
	        {
                maxRange = 1000.0;
	        }
        }
        else
        {
            throw std::invalid_argument("Invalid Range Value");
        }
    }
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
