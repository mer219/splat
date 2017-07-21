#ifndef MetricUnits_h
#define MetricUnits_h

#include "ArgumentProcessor.h"

class MetricUnits : ArgumentProcessor
{
public:
    MetricUnits(bool & useMetric);
    ~MetricUnits();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    bool & useMetric;
};
#endif
