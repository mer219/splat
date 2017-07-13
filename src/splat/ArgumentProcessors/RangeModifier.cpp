#include "RangeModifier.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

RangeModifier::RangeModifier(double & maxRange) :
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

bool RangeModifier::DoesThisOptionTakeAValue()
{
    return true;
}
    
void RangeModifier::ProcessArgument(const char argument[])
{
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
