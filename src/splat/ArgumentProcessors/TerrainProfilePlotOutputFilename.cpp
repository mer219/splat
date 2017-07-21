#include "TerrainProfilePlotOutputFilename.h"

#include "Arguments.h"

#include <cstring>
#include <stdexcept>

TerrainProfilePlotOutputFilename::TerrainProfilePlotOutputFilename(Arguments & arguments, char * terrainProfileFilename, bool & generateTerrainProfilePlot) :
    arguments(arguments),
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

void TerrainProfilePlotOutputFilename::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
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
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
