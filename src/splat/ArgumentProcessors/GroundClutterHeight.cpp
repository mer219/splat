#include "GroundClutterHeight.h"

#include "Arguments.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

GroundClutterHeight::GroundClutterHeight(Arguments & arguments, double & clutterHeight) :
    arguments(arguments),
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

void GroundClutterHeight::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
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
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
