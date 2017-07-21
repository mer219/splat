#ifndef LineOfSightCoverageReceiverHeight_h
#define LineOfSightCoverageReceiverHeight_h

#include "ArgumentProcessor.h"

class Arguments;

class LineOfSightCoverageReceiverHeight : ArgumentProcessor
{
public:
    LineOfSightCoverageReceiverHeight(Arguments & arguments, double & receiverAltitude, int & maxTransmitSites, bool & generateCoverageMap);
    ~LineOfSightCoverageReceiverHeight();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    double & receiverAltitude;
    int & maxTransmitterSites;
    bool & generateCoverageMap;
};
#endif
