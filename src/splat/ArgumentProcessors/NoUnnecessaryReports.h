#ifndef NoUnnecessaryReports_h
#define NoUnnecessaryReports_h

#include "ArgumentProcessor.h"

class NoUnnecessaryReports : ArgumentProcessor
{
public:
    NoUnnecessaryReports(bool & doNotPlotLineOfSightPaths, bool & doNotPrintSiteReports);
    ~NoUnnecessaryReports();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    bool & doNotPlotLineOfSightPaths;
    bool & doNotPrintSiteReports;
};
#endif
