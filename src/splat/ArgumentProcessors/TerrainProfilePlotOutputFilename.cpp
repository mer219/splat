#include "TerrainProfilePlotOutputFilename.h"

#include <cstring>
#include <stdexcept>

TerrainProfilePlotOutputFilename::TerrainProfilePlotOutputFilename(char * terrainProfileFilename, bool & generateTerrainProfilePlot) :
    terrainProfileFilename(terrainProfileFilename),
    generateTerrainProfilePlot(generateTerrainProfilePlot)
{
}

TerrainProfilePlotOutputFilename::~TerrainProfilePlotOutputFilename()
{
}

bool TerrainProfilePlotOutputFilename::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-p") == 0;
}

bool TerrainProfilePlotOutputFilename::DoesThisOptionTakeAValue()
{
    return true;
}
    
void TerrainProfilePlotOutputFilename::ProcessArgument(const char argument[])
{
    if (argument[0] && argument[0] != '-')
    {
        strncpy(terrainProfileFilename, argument, 253);
        generateTerrainProfilePlot = true;
    }
    else
    {
        throw std::invalid_argument("Invalid Terrain Profile Plot Output File Name");
    }
}
