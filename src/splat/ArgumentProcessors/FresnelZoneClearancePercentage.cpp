#include "FresnelZoneClearancePercentage.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

FresnelZoneClearancePercentage::FresnelZoneClearancePercentage(double& fresnelZoneClearancePercentage) :
    fresnelZoneClearancePercentage(fresnelZoneClearancePercentage)
{
}

FresnelZoneClearancePercentage::~FresnelZoneClearancePercentage()
{
}

bool FresnelZoneClearancePercentage::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-fz") == 0;
}

bool FresnelZoneClearancePercentage::DoesThisOptionTakeAValue()
{
    return true;
}
    
void FresnelZoneClearancePercentage::ProcessArgument(const char argument[])
{
    if (argument[0] && argument[0] != '-')
    {
        sscanf(argument, "%lf", &fresnelZoneClearancePercentage);
            
        if (fresnelZoneClearancePercentage < 0.0 || fresnelZoneClearancePercentage > 100.0)
            fresnelZoneClearancePercentage = 60.0;
        
        fresnelZoneClearancePercentage /= 100.0;
    }
    else
    {
        throw std::invalid_argument("Invalid Fresnel Zone Clearance Percentage");
    }
}
