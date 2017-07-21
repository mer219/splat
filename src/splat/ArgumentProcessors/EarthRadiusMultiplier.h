#ifndef EarthRadiusMultiplier_h
#define EarthRadiusMultiplier_h

#include "ArgumentProcessor.h"

class Arguments;

class EarthRadiusMultiplier : ArgumentProcessor
{
public:
    EarthRadiusMultiplier(Arguments & arguments, double & earthRadius);
    ~EarthRadiusMultiplier();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    double & earthRadius;
};
#endif
