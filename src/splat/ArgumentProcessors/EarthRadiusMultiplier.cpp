#include "EarthRadiusMultiplier.h"

#include "Arguments.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

EarthRadiusMultiplier::EarthRadiusMultiplier(Arguments & arguments, double & earthRadius) :
    arguments(arguments),
    earthRadius(earthRadius)
{
}

EarthRadiusMultiplier::~EarthRadiusMultiplier()
{
}

bool EarthRadiusMultiplier::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-m") == 0;
}

void EarthRadiusMultiplier::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();

        if (argument[0] && argument[0] != '-')
        {
            double earthRadiusMultiplier;

            sscanf(argument, "%lf", &earthRadiusMultiplier);
        
            if (earthRadiusMultiplier < 0.1)
	        {
                earthRadiusMultiplier = 1.0;
	        }
	        else if (earthRadiusMultiplier > 1.0e6)
	        {
                earthRadiusMultiplier = 1.0e6;
	        }
            
            earthRadius *= earthRadiusMultiplier;
        }
        else
        {
            throw std::invalid_argument("Invalid Earth Radius Multiplier");
        }
    }
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
