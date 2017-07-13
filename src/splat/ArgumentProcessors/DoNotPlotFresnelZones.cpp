#include "DoNotPlotFresnelZones.h"

#include <cstring>

DoNotPlotFresnelZones::DoNotPlotFresnelZones(bool & plotFresnelZones) :
    plotFresnelZones(plotFresnelZones)
{
}

DoNotPlotFresnelZones::~DoNotPlotFresnelZones()
{
}

bool DoNotPlotFresnelZones::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-nf") == 0;
}

bool DoNotPlotFresnelZones::DoesThisOptionTakeAValue()
{
    return false;
}
    
void DoNotPlotFresnelZones::ProcessArgument(const char * /*argument[]*/)
{
    plotFresnelZones = false;
}
