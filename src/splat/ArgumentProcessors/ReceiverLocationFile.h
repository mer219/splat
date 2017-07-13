#ifndef ReceiverLocationFile_h
#define ReceiverLocationFile_h

#include "ArgumentProcessor.h"

#include <vector>

class SiteLocationFile;
class Site;

class ReceiverLocationFile : ArgumentProcessor
{
public:
    ReceiverLocationFile(std::vector<Site *> & receiverSites, SiteLocationFile & siteLocationFile);
    ~ReceiverLocationFile();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    std::vector<Site *> & receiverSites;
    SiteLocationFile & siteLocationFile;
};
#endif
