#ifndef ContourThreshold_h
#define ContourThreshold_h

#include "ArgumentProcessor.h"

class ContourThreshold : ArgumentProcessor
{
public:
    ContourThreshold(int& contourThreshold);
    ~ContourThreshold();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    int& contourThreshold;
};
#endif
