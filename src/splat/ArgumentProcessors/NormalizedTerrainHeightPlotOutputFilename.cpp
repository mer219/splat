#include "NormalizedTerrainHeightPlotOutputFilename.h"

#include "Arguments.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

NormalizedTerrainHeightPlotOutputFilename::NormalizedTerrainHeightPlotOutputFilename(Arguments & arguments, char * normalizedTerrainHeightFilename, bool & generateNormalizedTerrainHeightPlot) :
    arguments(arguments),
    normalizedTerrainHeightFilename(normalizedTerrainHeightFilename),
    generateNormalizedTerrainHeightPlot(generateNormalizedTerrainHeightPlot)
{
}

NormalizedTerrainHeightPlotOutputFilename::~NormalizedTerrainHeightPlotOutputFilename()
{
}

bool NormalizedTerrainHeightPlotOutputFilename::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-H") == 0;
}

void NormalizedTerrainHeightPlotOutputFilename::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
        if (argument[0] && argument[0] != '-')
        {
            strncpy(normalizedTerrainHeightFilename, argument, 253);
            generateNormalizedTerrainHeightPlot = true;
        }
        else
        {
            throw std::invalid_argument("Invalid Normalized Terrain Height Plot Output File Name");
        }
    }
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
