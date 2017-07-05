#ifndef TerrainElevationPlotOutputFilename_h
#define TerrainElevationPlotOutputFilename_h

#include "ArgumentProcessor.h"

class TerrainElevationPlotOutputFilename : ArgumentProcessor
{
public:
    TerrainElevationPlotOutputFilename(char* terrainElevationFilename, bool& generateTerrainElevationPlot);
    ~TerrainElevationPlotOutputFilename();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    char* terrainElevationFilename;
    bool& generateTerrainElevationPlot;
};
#endif
