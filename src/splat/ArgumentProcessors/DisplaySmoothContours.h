#ifndef DisplaySmoothContours_h
#define DisplaySmoothContours_h

#include "ArgumentProcessor.h"

class DisplaySmoothContours : ArgumentProcessor
{
public:
    DisplaySmoothContours(bool & displaySmoothContours);
    ~DisplaySmoothContours();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    bool & displaySmoothContours;
};
#endif
