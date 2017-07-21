#include "FresnelZoneClearancePercentage.h"

#include "Arguments.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

FresnelZoneClearancePercentage::FresnelZoneClearancePercentage(Arguments & argumnets, double & fresnelZoneClearancePercentage) :
    arguments(arguments),
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

void FresnelZoneClearancePercentage::ProcessArgument()
{   
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
        if (argument[0] && argument[0] != '-')
        {
            sscanf(argument, "%lf", &fresnelZoneClearancePercentage);
            
            if (fresnelZoneClearancePercentage < 0.0 || fresnelZoneClearancePercentage > 100.0)
	        {
                fresnelZoneClearancePercentage = 60.0;
	        }
            
            fresnelZoneClearancePercentage /= 100.0;
        }
        else
        {
            throw std::invalid_argument("Invalid Fresnel Zone Clearance Percentage");
        }
    }
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
