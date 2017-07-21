#ifndef RangeModifier_h
#define RangeModifier_h

#include "ArgumentProcessor.h"

class Arguments;

class RangeModifier : ArgumentProcessor
{
public:
    RangeModifier(Arguments & arguments, double & maxRange);
    ~RangeModifier();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    double & maxRange;
};
#endif
