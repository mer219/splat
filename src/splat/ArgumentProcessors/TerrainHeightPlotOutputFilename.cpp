#include "TerrainHeightPlotOutputFilename.h"

#include "Arguments.h"

#include <cstring>
#include <stdexcept>

TerrainHeightPlotOutputFilename::TerrainHeightPlotOutputFilename(Arguments & arguments, char * terrainHeightFilename, bool & generateTerrainHeightPlot) :
    arguments(arguments),
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

void TerrainHeightPlotOutputFilename::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
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
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
