#include "TransmitterLocationFile.h"

#include "../FileUtilities/SiteLocationFile.h"
#include "Arguments.h"

#include <cstring>
#include <stdexcept>

TransmitterLocationFile::TransmitterLocationFile(Arguments & arguments, std::vector<Site *> & transmitterLocations, SiteLocationFile & siteLocationFile) :
        arguments(arguments),
        transmitterLocations(transmitterLocations),
        siteLocationFile(siteLocationFile)
{
}

TransmitterLocationFile::~TransmitterLocationFile()
{
}

bool TransmitterLocationFile::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-t") == 0;
}

void TransmitterLocationFile::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
        if (argument[0] && argument[0] != '-' && transmitterLocations.size() < 30)
        {
            char fileName[255];
	        strcpy(fileName, argument);
            transmitterLocations.push_back(siteLocationFile.ReadFile(fileName));
        }
        else
        {
            throw std::invalid_argument("Invalid Transmitter Location File Name");
        }
    }
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
