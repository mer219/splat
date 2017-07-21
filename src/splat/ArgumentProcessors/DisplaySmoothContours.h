#ifndef DisplaySmoothContours_h
#define DisplaySmoothContours_h

#include "ArgumentProcessor.h"

class DisplaySmoothContours : ArgumentProcessor
{
public:
    DisplaySmoothContours(bool & displaySmoothContours);
    ~DisplaySmoothContours();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    bool & displaySmoothContours;
};
#endif
