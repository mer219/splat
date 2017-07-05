#ifndef RangeModifier_h
#define RangeModifier_h

#include "ArgumentProcessor.h"

class RangeModifier : ArgumentProcessor
{
public:
    RangeModifier(double& maxRange);
    ~RangeModifier();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    double& maxRange;
};
#endif
