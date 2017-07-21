#ifndef FresnelZoneClearancePercentage_h
#define FresnelZoneClearancePercentage_h

#include "ArgumentProcessor.h"

class Arguments;

class FresnelZoneClearancePercentage : ArgumentProcessor
{
public:
    FresnelZoneClearancePercentage(Arguments & arguments, double & fresnelZoneClearancePercentage);
    ~FresnelZoneClearancePercentage();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    double & fresnelZoneClearancePercentage;
};
#endif
