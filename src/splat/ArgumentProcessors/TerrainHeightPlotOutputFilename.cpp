#include "TerrainHeightPlotOutputFilename.h"

#include <cstring>
#include <stdexcept>

TerrainHeightPlotOutputFilename::TerrainHeightPlotOutputFilename(char * terrainHeightFilename, bool & generateTerrainHeightPlot) :
    terrainHeightFilename(terrainHeightFilename),
    generateTerrainHeightPlot(generateTerrainHeightPlot)
{
}

TerrainHeightPlotOutputFilename::~TerrainHeightPlotOutputFilename()
{
}

bool TerrainHeightPlotOutputFilename::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-h") == 0;
}

bool TerrainHeightPlotOutputFilename::DoesThisOptionTakeAValue()
{
    return true;
}
    
void TerrainHeightPlotOutputFilename::ProcessArgument(const char argument[])
{
    if (argument[0] && argument[0] != '-')
    {
        strncpy(terrainHeightFilename, argument, 253);
        generateTerrainHeightPlot = true;
    }
    else
    {
        throw std::invalid_argument("Invalid Terrain Height Plot Output File Name");
    }
}
