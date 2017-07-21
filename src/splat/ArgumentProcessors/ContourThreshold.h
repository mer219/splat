#ifndef ContourThreshold_h
#define ContourThreshold_h

#include "ArgumentProcessor.h"

class Arguments;

class ContourThreshold : ArgumentProcessor
{
public:
    ContourThreshold(Arguments & arguments, int & contourThreshold);
    ~ContourThreshold();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    int & contourThreshold;
};
#endif
