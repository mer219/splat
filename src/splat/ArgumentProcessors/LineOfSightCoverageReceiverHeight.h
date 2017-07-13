#ifndef LineOfSightCoverageReceiverHeight_h
#define LineOfSightCoverageReceiverHeight_h

#include "ArgumentProcessor.h"

class LineOfSightCoverageReceiverHeight : ArgumentProcessor
{
public:
    LineOfSightCoverageReceiverHeight(double & receiverAltitude, int & maxTransmitSites, bool & generateCoverageMap);
    ~LineOfSightCoverageReceiverHeight();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    double & receiverAltitude;
    int & maxTransmitSites;
    bool & generateCoverageMap;
};
#endif
