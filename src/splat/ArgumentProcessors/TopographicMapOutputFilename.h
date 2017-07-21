#ifndef TopographicMapOutputFilename_h
#define TopographicMapOutputFilename_h

#include "ArgumentProcessor.h"

class Arguments;

class TopographicMapOutputFilename : ArgumentProcessor
{
public:
    TopographicMapOutputFilename(Arguments & arguments, char mapFile[], bool & generateMap);
    ~TopographicMapOutputFilename();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    char * mapFile;
    bool & generateTopographicalMap;
};
#endif
