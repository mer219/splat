#include "NoUnnecessaryReports.h"

#include <cstring>

NoUnnecessaryReports::NoUnnecessaryReports(bool & doNotPlotLineOfSightPaths, bool & doNotPrintSiteReports) :
    doNotPlotLineOfSightPaths(doNotPlotLineOfSightPaths),
    doNotPrintSiteReports(doNotPrintSiteReports)
{
}

NoUnnecessaryReports::~NoUnnecessaryReports()
{
}

bool NoUnnecessaryReports::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-N") == 0;
}

bool NoUnnecessaryReports::DoesThisOptionTakeAValue()
{
    return false;
}
    
void NoUnnecessaryReports::ProcessArgument(const char * /*argument[]*/)
{
    doNotPlotLineOfSightPaths = true;
    doNotPrintSiteReports = true;
}
