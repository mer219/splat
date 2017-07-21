#include "TerrainElevationPlotOutputFilename.h"

#include "Arguments.h"

#include <cstring>
#include <stdexcept>

TerrainElevationPlotOutputFilename::TerrainElevationPlotOutputFilename(Arguments & arguments, char * terrainElevationFilename, bool & generateTerrainElevationPlot) :
    arguments(arguments),
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

void TerrainElevationPlotOutputFilename::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
        if (argument[0] && argument[0] != '-')
        {
            strncpy(terrainElevationFilename, argument, 253);
            generateTerrainElevationPlot = true;
        }
        else
        {
            throw std::invalid_argument("Invalid Terrain Elevation Plot Output File Name");
        }
    }
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
