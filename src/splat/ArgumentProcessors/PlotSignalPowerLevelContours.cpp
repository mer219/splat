#include "PlotSignalPowerLevelContours.h"

#include <cstring>

PlotSignalPowerLevelContours::PlotSignalPowerLevelContours(bool & plotSignalPowerLevelContours) :
    plotSignalPowerLevelContours(plotSignalPowerLevelContours)
{
}

PlotSignalPowerLevelContours::~PlotSignalPowerLevelContours()
{
}

bool PlotSignalPowerLevelContours::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-dbm") == 0;
}

void PlotSignalPowerLevelContours::ProcessArgument()
{
    plotSignalPowerLevelContours = true;
}
