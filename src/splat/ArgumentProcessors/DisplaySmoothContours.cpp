#include "DisplaySmoothContours.h"

#include <cstring>

DisplaySmoothContours::DisplaySmoothContours(bool & displaySmoothContours) :
    displaySmoothContours(displaySmoothContours)
{
}

DisplaySmoothContours::~DisplaySmoothContours()
{
}

bool DisplaySmoothContours::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "sc") == 0;
}

bool DisplaySmoothContours::DoesThisOptionTakeAValue()
{
    return false;
}
    
void DisplaySmoothContours::ProcessArgument(const char * /*argument[]*/)
{
    displaySmoothContours = true;
}
