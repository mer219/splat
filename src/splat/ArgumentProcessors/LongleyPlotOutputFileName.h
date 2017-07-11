#ifndef LongleyPlotOutputFileName_h
#define LongleyPlotOutputFileName_h

#include "ArgumentProcessor.h"

class LongleyPlotOutputFileName : ArgumentProcessor
{
public:
    LongleyPlotOutputFileName(char * longleyFileName, bool & generateLongleyPlot);
    ~LongleyPlotOutputFileName();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    char * longleyFileName;
    bool & generateLongleyPlot;
};
#endif
