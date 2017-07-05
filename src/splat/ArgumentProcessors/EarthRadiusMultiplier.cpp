#include "EarthRadiusMultiplier.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

EarthRadiusMultiplier::EarthRadiusMultiplier(double& earthRadius) :
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

bool EarthRadiusMultiplier::DoesThisOptionTakeAValue()
{
    return true;
}
    
void EarthRadiusMultiplier::ProcessArgument(const char argument[])
{
    if (argument[0] && argument[0] != '-')
    {
        double earthRadiusMultiplier;

        sscanf(argument, "%lf", &earthRadiusMultiplier);
        
        if (earthRadiusMultiplier < 0.1)
            earthRadiusMultiplier = 1.0;
            
        if (earthRadiusMultiplier > 1.0e6)
            earthRadiusMultiplier = 1.0e6;
        
        earthRadius *= earthRadiusMultiplier;
    }
    else
    {
        throw std::invalid_argument("Invalid Earth Radius Multiplier");
    }
}
