#ifndef TerrainHeightPlotOutputFilename_h
#define TerrainHeightPlotOutputFilename_h

#include "ArgumentProcessor.h"

class TerrainHeightPlotOutputFilename : ArgumentProcessor
{
public:
    TerrainHeightPlotOutputFilename(char* terrainHeightFilename, bool& generateTerrainHeightPlot);
    ~TerrainHeightPlotOutputFilename();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    char* terrainHeightFilename;
    bool& generateTerrainHeightPlot;
};
#endif
