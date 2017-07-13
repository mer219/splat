#ifndef TopographicMapOutputFilename_h
#define TopographicMapOutputFilename_h

#include "ArgumentProcessor.h"

class TopographicMapOutputFilename : ArgumentProcessor
{
public:
    TopographicMapOutputFilename(char mapFile[], bool & generateMap);
    ~TopographicMapOutputFilename();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    char * mapFile;
    bool & generateTopographicalMap;
};
#endif
