#ifndef DisplayGreyscaleTopographyAsWhite_h
#define DisplayGreyscaleTopographyAsWhite_h

#include "ArgumentProcessor.h"

class DisplayGreyscaleTopographyAsWhite : ArgumentProcessor
{
public:
    DisplayGreyscaleTopographyAsWhite(bool & displayGreyscaleTopographyAsWhite);
    ~DisplayGreyscaleTopographyAsWhite();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    bool & displayGreyscaleTopographyAsWhite;
};
#endif
