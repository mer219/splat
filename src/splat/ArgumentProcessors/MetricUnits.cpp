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

void MetricUnits::ProcessArgument()
{
    useMetric = true;
}
