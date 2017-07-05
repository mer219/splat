#ifndef TerrainProfilePlotOutputFilename_h
#define TerrainProfilePlotOutputFilename_h

#include "ArgumentProcessor.h"

class TerrainProfilePlotOutputFilename : ArgumentProcessor
{
public:
    TerrainProfilePlotOutputFilename(char* terrainProfileFilename, bool& generateTerrainProfilePlot);
    ~TerrainProfilePlotOutputFilename();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    char* terrainProfileFilename;
    bool& generateTerrainProfilePlot;
};
#endif
