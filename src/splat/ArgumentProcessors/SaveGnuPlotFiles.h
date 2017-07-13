#ifndef SaveGnuPlotFiles_h
#define SaveGnuPlotFiles_h

#include "ArgumentProcessor.h"

class SaveGnuPlotFiles : ArgumentProcessor
{
public:
    SaveGnuPlotFiles(bool & saveGnuPlotFiles);
    ~SaveGnuPlotFiles();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    bool & saveGnuPlotFiles;
};
#endif
