#include "GroundClutterHeight.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

GroundClutterHeight::GroundClutterHeight(double & clutterHeight) :
    clutterHeight(clutterHeight)
{
}

GroundClutterHeight::~GroundClutterHeight()
{
}

bool GroundClutterHeight::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-gc") == 0;
}

bool GroundClutterHeight::DoesThisOptionTakeAValue()
{
    return true;
}
    
void GroundClutterHeight::ProcessArgument(const char argument[])
{
    if (argument[0] && argument[0] != '-')
    {
        sscanf(argument, "%lf", &clutterHeight);
            
        if (clutterHeight < 0.0)
	{
            clutterHeight = 0.0;
	}
    }
    else
    {
        throw std::invalid_argument("Invalid Ground Clutter Height");
    }
}
