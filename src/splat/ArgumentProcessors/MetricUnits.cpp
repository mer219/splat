#include "MetricUnits.h"

#include <cstring>

MetricUnits::MetricUnits(bool & useMetric) :
    useMetric(useMetric)
{
}

MetricUnits::~MetricUnits()
{
}

bool MetricUnits::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-metric") == 0;
}

bool MetricUnits::DoesThisOptionTakeAValue()
{
    return false;
}
    
void MetricUnits::ProcessArgument(const char * /*argument[]*/)
{
    useMetric = true;
}
