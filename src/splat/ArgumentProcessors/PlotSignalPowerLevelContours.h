#ifndef PlotSignalPowerLevelContours_h
#define PlotSignalPowerLevelContours_h

#include "ArgumentProcessor.h"

class PlotSignalPowerLevelContours : ArgumentProcessor
{
public:
    PlotSignalPowerLevelContours(bool & plotSignalPowerLevelContours);
    ~PlotSignalPowerLevelContours();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    bool & plotSignalPowerLevelContours;
};
#endif
