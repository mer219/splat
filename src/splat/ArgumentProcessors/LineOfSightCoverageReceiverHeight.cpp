#include "LineOfSightCoverageReceiverHeight.h"

#include "Arguments.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

LineOfSightCoverageReceiverHeight::LineOfSightCoverageReceiverHeight(Arguments & arguments, double & receiverAltitude, int & maxTransmitterSites, bool & generateCoverageMap) :
    arguments(arguments),
    receiverAltitude(receiverAltitude),
    maxTransmitterSites(maxTransmitterSites),
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

void LineOfSightCoverageReceiverHeight::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
        if (argument[0] && argument[0] != '-')
        {
            sscanf(argument, "%lf", &receiverAltitude);
            generateCoverageMap = 1;
            maxTransmitterSites = 4;
        }
        else
        {
            throw std::invalid_argument("Invalid Line of Sight Coverage Receiver Height");
        }
    }
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
