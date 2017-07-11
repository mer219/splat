#ifndef TransmitterLocationFile_h
#define TransmitterLocationFile_h

#include "ArgumentProcessor.h"

#include "../include/Site.h"

#include <vector>

class SiteLocationFile;

class TransmitterLocationFile : ArgumentProcessor
{
public:
    TransmitterLocationFile(std::vector<Site*> & transmitterLocations,
        SiteLocationFile & siteLocationFile);
    ~TransmitterLocationFile();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    std::vector<Site*> & transmitterLocations;
    SiteLocationFile & siteLocationFile;
};
#endif
