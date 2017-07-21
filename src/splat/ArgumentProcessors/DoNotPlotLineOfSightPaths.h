#ifndef DoNotPlotLineOfSightPaths_h
#define DoNotPlotLineOfSightPaths_h

#include "ArgumentProcessor.h"

class DoNotPlotLineOfSightPaths : ArgumentProcessor
{
public:
    DoNotPlotLineOfSightPaths(bool & doNotPlotLineOfSightPaths);
    ~DoNotPlotLineOfSightPaths();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    bool & doNotPlotLineOfSightPaths;
};
#endif
