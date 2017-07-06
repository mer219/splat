#ifndef NoUnnecessaryReports_h
#define NoUnnecessaryReports_h

#include "ArgumentProcessor.h"

class NoUnnecessaryReports : ArgumentProcessor
{
public:
    NoUnnecessaryReports(bool& doNotPlotLineOfSightPaths, bool& doNotPrintSiteReports);
    ~NoUnnecessaryReports();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    bool& doNotPlotLineOfSightPaths;
    bool& doNotPrintSiteReports;
};
#endif
