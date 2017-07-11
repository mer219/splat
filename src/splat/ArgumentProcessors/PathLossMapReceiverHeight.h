#ifndef PathLossMapReceiverHeight_h
#define PathLossMapReceiverHeight_h

#include "ArgumentProcessor.h"

class PathLossMapReceiverHeight : ArgumentProcessor
{
public:
    PathLossMapReceiverHeight(double & receiverAltitude, bool & generateLossMap);
    ~PathLossMapReceiverHeight();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    double & receiverAltitude;
    bool & generateLossMap;
};
#endif
