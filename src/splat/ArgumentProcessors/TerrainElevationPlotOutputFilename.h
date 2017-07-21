#ifndef TerrainElevationPlotOutputFilename_h
#define TerrainElevationPlotOutputFilename_h

#include "ArgumentProcessor.h"

class Arguments;

class TerrainElevationPlotOutputFilename : ArgumentProcessor
{
public:
    TerrainElevationPlotOutputFilename(Arguments &arguments, char * terrainElevationFilename, bool & generateTerrainElevationPlot);
    ~TerrainElevationPlotOutputFilename();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    char * terrainElevationFilename;
    bool & generateTerrainElevationPlot;
};
#endif
