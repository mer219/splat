#ifndef TerrainProfilePlotOutputFilename_h
#define TerrainProfilePlotOutputFilename_h

#include "ArgumentProcessor.h"

class Arguments;

class TerrainProfilePlotOutputFilename : ArgumentProcessor
{
public:
    TerrainProfilePlotOutputFilename(Arguments & arguments, char * terrainProfileFilename, bool & generateTerrainProfilePlot);
    ~TerrainProfilePlotOutputFilename();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    char * terrainProfileFilename;
    bool & generateTerrainProfilePlot;
};
#endif
