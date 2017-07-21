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

void DoNotPlotLineOfSightPaths::ProcessArgument()
{
    doNotPlotLineOfSightPaths = true;
}
