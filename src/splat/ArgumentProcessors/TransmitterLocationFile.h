#ifndef TransmitterLocationFile_h
#define TransmitterLocationFile_h

#include "ArgumentProcessor.h"

#include "../include/Site.h"

#include <vector>

class SiteLocationFile;
class Arguments;

class TransmitterLocationFile : ArgumentProcessor
{
public:
    TransmitterLocationFile(Arguments & arguments, std::vector<Site *> & transmitterLocations, SiteLocationFile & siteLocationFile);
    ~TransmitterLocationFile();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    std::vector<Site *> & transmitterLocations;
    SiteLocationFile & siteLocationFile;
};
#endif
