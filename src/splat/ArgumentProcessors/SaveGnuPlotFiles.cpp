#include "SaveGnuPlotFiles.h"

#include <cstring>

SaveGnuPlotFiles::SaveGnuPlotFiles(bool& saveGnuPlotFiles) :
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

bool SaveGnuPlotFiles::DoesThisOptionTakeAValue()
{
    return false;
}
    
void SaveGnuPlotFiles::ProcessArgument(const char * /*argument[]*/)
{
    saveGnuPlotFiles = true;
}
