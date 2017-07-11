#include "TransmitterLocationFile.h"

#include "../FileUtilities/SiteLocationFile.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

TransmitterLocationFile::TransmitterLocationFile(std::vector<Site*> & transmitterLocations,
    SiteLocationFile & siteLocationFile) :
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

bool TransmitterLocationFile::DoesThisOptionTakeAValue()
{
    return true;
}
    
void TransmitterLocationFile::ProcessArgument(const char argument[])
{
    if (argument[0] && argument[0] != '-' && transmitterLocations.size() < 30)
    {
        char fileName[255];
	strcpy(fileName, argument);
        transmitterLocations.push_back(siteLocationFile.ReadFile(fileName));
    }
    else
    {
        throw std::invalid_argument("Invalid Range Value");
    }
}
