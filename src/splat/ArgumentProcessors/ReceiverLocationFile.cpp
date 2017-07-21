#include "ReceiverLocationFile.h"

#include "Arguments.h"
#include "../FileUtilities/SiteLocationFile.h"
#include "../include/Site.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

ReceiverLocationFile::ReceiverLocationFile(Arguments & arguments, std::vector<Site *> & receiverSites, SiteLocationFile & siteLocationFile) :
    arguments(arguments),
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

void ReceiverLocationFile::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();

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
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
