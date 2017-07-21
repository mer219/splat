#ifndef SaveGnuPlotFiles_h
#define SaveGnuPlotFiles_h

#include "ArgumentProcessor.h"

class SaveGnuPlotFiles : ArgumentProcessor
{
public:
    SaveGnuPlotFiles(bool & saveGnuPlotFiles);
    ~SaveGnuPlotFiles();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    bool & saveGnuPlotFiles;
};
#endif
