#ifndef ReceiverLocationFile_h
#define ReceiverLocationFile_h

#include "ArgumentProcessor.h"

#include <vector>

class Arguments;
class SiteLocationFile;
class Site;

class ReceiverLocationFile : ArgumentProcessor
{
public:
    ReceiverLocationFile(Arguments & arguments, std::vector<Site *> & receiverSites, SiteLocationFile & siteLocationFile);
    ~ReceiverLocationFile();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    std::vector<Site *> & receiverSites;
    SiteLocationFile & siteLocationFile;
};
#endif
