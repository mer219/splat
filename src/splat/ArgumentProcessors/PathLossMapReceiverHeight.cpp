#include "PathLossMapReceiverHeight.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

PathLossMapReceiverHeight::PathLossMapReceiverHeight(double & receiverAltitude, bool & generateLossMap) :
    receiverAltitude(receiverAltitude),
    generateLossMap(generateLossMap)
{
}

PathLossMapReceiverHeight::~PathLossMapReceiverHeight()
{
}

bool PathLossMapReceiverHeight::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-L") == 0;
}

bool PathLossMapReceiverHeight::DoesThisOptionTakeAValue()
{
    return true;
}
    
void PathLossMapReceiverHeight::ProcessArgument(const char argument[])
{
    if (argument[0] && argument[0] != '-')
    {
        sscanf(argument, "%lf", &receiverAltitude);
        generateLossMap = 1;
    }
    else
    {
        throw std::invalid_argument("Invalid Path Loss Map Receiver Height");
    }

//if (coverage)
//fprintf(stdout,"c and L are exclusive options, ignoring L.\n");
}
