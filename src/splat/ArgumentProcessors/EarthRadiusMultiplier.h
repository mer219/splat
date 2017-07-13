#ifndef EarthRadiusMultiplier_h
#define EarthRadiusMultiplier_h

#include "ArgumentProcessor.h"

class EarthRadiusMultiplier : ArgumentProcessor
{
public:
    EarthRadiusMultiplier(double & earthRadius);
    ~EarthRadiusMultiplier();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    double & earthRadius;
};
#endif
