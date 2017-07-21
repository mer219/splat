#ifndef TerrainHeightPlotOutputFilename_h
#define TerrainHeightPlotOutputFilename_h

#include "ArgumentProcessor.h"

class Arguments;

class TerrainHeightPlotOutputFilename : ArgumentProcessor
{
public:
    TerrainHeightPlotOutputFilename(Arguments & arguments, char * terrainHeightFilename, bool & generateTerrainHeightPlot);
    ~TerrainHeightPlotOutputFilename();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    char * terrainHeightFilename;
    bool & generateTerrainHeightPlot;
};
#endif
