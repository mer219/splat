#ifndef LongleyPlotOutputFileName_h
#define LongleyPlotOutputFileName_h

#include "ArgumentProcessor.h"

class Arguments;

class LongleyPlotOutputFileName : ArgumentProcessor
{
public:
    LongleyPlotOutputFileName(Arguments & arguments, char * longleyFileName, bool & generateLongleyPlot);
    ~LongleyPlotOutputFileName();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    char * longleyFileName;
    bool & generateLongleyPlot;
};
#endif
