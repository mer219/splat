#include "LongleyPlotOutputFileName.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

LongleyPlotOutputFileName::LongleyPlotOutputFileName(char * longleyFileName, bool & generateLongleyPlot) :
    longleyFileName(longleyFileName),
    generateLongleyPlot(generateLongleyPlot)
{
}

LongleyPlotOutputFileName::~LongleyPlotOutputFileName()
{
}

bool LongleyPlotOutputFileName::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-l") == 0;
}

bool LongleyPlotOutputFileName::DoesThisOptionTakeAValue()
{
    return true;
}
    
void LongleyPlotOutputFileName::ProcessArgument(const char argument[])
{
    if (argument[0] && argument[0] != '-')
    {
        strncpy(longleyFileName, argument, 253);
        generateLongleyPlot = 1;
    }
    else
    {
        throw std::invalid_argument("Invalid Range Value");
    }
}
