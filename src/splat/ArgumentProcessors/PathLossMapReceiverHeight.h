#ifndef PathLossMapReceiverHeight_h
#define PathLossMapReceiverHeight_h

#include "ArgumentProcessor.h"

class Arguments;

class PathLossMapReceiverHeight : ArgumentProcessor
{
public:
    PathLossMapReceiverHeight(Arguments & arguments, double & receiverAltitude, bool & generateLossMap);
    ~PathLossMapReceiverHeight();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    double & receiverAltitude;
    bool & generateLossMap;
};
#endif
