#include "DoNotPlotLineOfSightPaths.h"

#include <cstring>

DoNotPlotLineOfSightPaths::DoNotPlotLineOfSightPaths(bool & doNotPlotLineOfSightPaths) :
    doNotPlotLineOfSightPaths(doNotPlotLineOfSightPaths)
{
}

DoNotPlotLineOfSightPaths::~DoNotPlotLineOfSightPaths()
{
}

bool DoNotPlotLineOfSightPaths::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-n") == 0;
}

bool DoNotPlotLineOfSightPaths::DoesThisOptionTakeAValue()
{
    return false;
}
    
void DoNotPlotLineOfSightPaths::ProcessArgument(const char * /*argument[]*/)
{
    doNotPlotLineOfSightPaths = true;
}
