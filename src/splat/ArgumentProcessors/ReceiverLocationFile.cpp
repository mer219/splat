#include "ReceiverLocationFile.h"

#include "../FileUtilities/SiteLocationFile.h"
#include "../include/Site.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

ReceiverLocationFile::ReceiverLocationFile(std::vector<Site *> & receiverSites, SiteLocationFile & siteLocationFile) :
    receiverSites(receiverSites),
    siteLocationFile(siteLocationFile)
{
}

ReceiverLocationFile::~ReceiverLocationFile()
{
}

bool ReceiverLocationFile::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-r") == 0;
}

bool ReceiverLocationFile::DoesThisOptionTakeAValue()
{
    return true;
}
    
void ReceiverLocationFile::ProcessArgument(const char argument[])
{
    if (argument[0] && argument[0] != '-')
    {
        char receiverFileName[255];
        strncpy(receiverFileName, argument, 253);
        receiverSites.push_back(siteLocationFile.ReadFile(receiverFileName));
    }
    else
    {
        throw std::invalid_argument("Invalid ReceiverLocation File Name");
    }
}
