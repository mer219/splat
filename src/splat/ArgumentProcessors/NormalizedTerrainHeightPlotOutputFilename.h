#ifndef NormalizedTerrainHeightPlotOutputFilename_h
#define NormalizedTerrainHeightPlotOutputFilename_h

#include "ArgumentProcessor.h"

class Arguments;

class NormalizedTerrainHeightPlotOutputFilename : ArgumentProcessor
{
public:
    NormalizedTerrainHeightPlotOutputFilename(Arguments & arguments, char * normalizedTerrainHeightFilename, bool & generateNormalizedTerrainHeightPlot);
    ~NormalizedTerrainHeightPlotOutputFilename();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    char * normalizedTerrainHeightFilename;
    bool & generateNormalizedTerrainHeightPlot;
};
#endif
