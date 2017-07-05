#include "LineOfSightCoverageReceiverHeight.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

LineOfSightCoverageReceiverHeight::LineOfSightCoverageReceiverHeight(double& receiverAltitude, int& maxTransmitSites, bool& generateCoverageMap) :
    receiverAltitude(receiverAltitude),
    maxTransmitSites(maxTransmitSites),
    generateCoverageMap(generateCoverageMap)
{
}

LineOfSightCoverageReceiverHeight::~LineOfSightCoverageReceiverHeight()
{
}

bool LineOfSightCoverageReceiverHeight::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-c") == 0;
}

bool LineOfSightCoverageReceiverHeight::DoesThisOptionTakeAValue()
{
    return true;
}
    
void LineOfSightCoverageReceiverHeight::ProcessArgument(const char argument[])
{
    if (argument[0] && argument[0] != '-')
    {
        sscanf(argument, "%lf", &receiverAltitude);
        generateCoverageMap=1;
        maxTransmitSites=4;
    }
    else
    {
        throw std::invalid_argument("Invalid Line of Sight Coverage Receiver Height");
    }
}
