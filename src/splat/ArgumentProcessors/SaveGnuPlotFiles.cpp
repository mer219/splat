#include "SaveGnuPlotFiles.h"

#include <cstring>

SaveGnuPlotFiles::SaveGnuPlotFiles(bool & saveGnuPlotFiles) :
    saveGnuPlotFiles(saveGnuPlotFiles)
{
}

SaveGnuPlotFiles::~SaveGnuPlotFiles()
{
}

bool SaveGnuPlotFiles::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-gpsav") == 0;
}

void SaveGnuPlotFiles::ProcessArgument()
{
    saveGnuPlotFiles = true;
}
