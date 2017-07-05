#ifndef NormalizedTerrainHeightPlotOutputFilename_h
#define NormalizedTerrainHeightPlotOutputFilename_h

#include "ArgumentProcessor.h"

class NormalizedTerrainHeightPlotOutputFilename : ArgumentProcessor
{
public:
    NormalizedTerrainHeightPlotOutputFilename(char* normalizedTerrainHeightFilename, bool& generateNormalizedTerrainHeightPlot);
    ~NormalizedTerrainHeightPlotOutputFilename();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    char* normalizedTerrainHeightFilename;
    bool& generateNormalizedTerrainHeightPlot;
};
#endif
