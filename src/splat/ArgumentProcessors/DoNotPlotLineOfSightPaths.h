#ifndef DoNotPlotLineOfSightPaths_h
#define DoNotPlotLineOfSightPaths_h

#include "ArgumentProcessor.h"

class DoNotPlotLineOfSightPaths : ArgumentProcessor
{
public:
    DoNotPlotLineOfSightPaths(bool & doNotPlotLineOfSightPaths);
    ~DoNotPlotLineOfSightPaths();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    bool & doNotPlotLineOfSightPaths;
};
#endif
