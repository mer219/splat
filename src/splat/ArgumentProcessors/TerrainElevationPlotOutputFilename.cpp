#include "TerrainElevationPlotOutputFilename.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

TerrainElevationPlotOutputFilename::TerrainElevationPlotOutputFilename(char* terrainElevationFilename, bool& generateTerrainElevationPlot) :
    terrainElevationFilename(terrainElevationFilename),
    generateTerrainElevationPlot(generateTerrainElevationPlot)
{
}

TerrainElevationPlotOutputFilename::~TerrainElevationPlotOutputFilename()
{
}

bool TerrainElevationPlotOutputFilename::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-e") == 0;
}

bool TerrainElevationPlotOutputFilename::DoesThisOptionTakeAValue()
{
    return true;
}
    
void TerrainElevationPlotOutputFilename::ProcessArgument(const char argument[])
{
    if (argument[0] && argument[0] != '-')
    {
        strncpy(terrainElevationFilename, argument, 253);
        generateTerrainElevationPlot = true;
    }
    else
    {
        throw std::invalid_argument("Invalid Range Value");
    }
}
