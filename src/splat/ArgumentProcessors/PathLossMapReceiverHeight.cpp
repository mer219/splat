#include "PathLossMapReceiverHeight.h"

#include "Arguments.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

PathLossMapReceiverHeight::PathLossMapReceiverHeight(Arguments & arguments, double & receiverAltitude, bool & generateLossMap) :
    arguments(arguments),
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

void PathLossMapReceiverHeight::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
        if (argument[0] && argument[0] != '-')
        {
            sscanf(argument, "%lf", &receiverAltitude);
            generateLossMap = 1;
        }
        else
        {
            throw std::invalid_argument("Invalid Path Loss Map Receiver Height");
        }
    }
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }

//if (coverage)
//fprintf(stdout,"c and L are exclusive options, ignoring L.\n");
}
