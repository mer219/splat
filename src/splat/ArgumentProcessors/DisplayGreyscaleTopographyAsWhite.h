#ifndef DisplayGreyscaleTopographyAsWhite_h
#define DisplayGreyscaleTopographyAsWhite_h

#include "ArgumentProcessor.h"

class DisplayGreyscaleTopographyAsWhite : ArgumentProcessor
{
public:
    DisplayGreyscaleTopographyAsWhite(bool& displayGreyscaleTopographyAsWhite);
    ~DisplayGreyscaleTopographyAsWhite();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    bool& displayGreyscaleTopographyAsWhite;
};
#endif
