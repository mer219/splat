#ifndef FresnelZoneClearancePercentage_h
#define FresnelZoneClearancePercentage_h

#include "ArgumentProcessor.h"

class FresnelZoneClearancePercentage : ArgumentProcessor
{
public:
    FresnelZoneClearancePercentage(double& fresnelZoneClearancePercentage);
    ~FresnelZoneClearancePercentage();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    double& fresnelZoneClearancePercentage;
};
#endif
