#include "NormalizedTerrainHeightPlotOutputFilename.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

NormalizedTerrainHeightPlotOutputFilename::NormalizedTerrainHeightPlotOutputFilename(char * normalizedTerrainHeightFilename, bool & generateNormalizedTerrainHeightPlot) :
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

bool NormalizedTerrainHeightPlotOutputFilename::DoesThisOptionTakeAValue()
{
    return true;
}
    
void NormalizedTerrainHeightPlotOutputFilename::ProcessArgument(const char argument[])
{
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
