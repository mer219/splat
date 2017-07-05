#include "DisplayGreyscaleTopographyAsWhite.h"

#include <cstring>

DisplayGreyscaleTopographyAsWhite::DisplayGreyscaleTopographyAsWhite(bool& displayGreyscaleTopographyAsWhite) :
    displayGreyscaleTopographyAsWhite(displayGreyscaleTopographyAsWhite)
{
}

DisplayGreyscaleTopographyAsWhite::~DisplayGreyscaleTopographyAsWhite()
{
}

bool DisplayGreyscaleTopographyAsWhite::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-ngs") == 0;
}

bool DisplayGreyscaleTopographyAsWhite::DoesThisOptionTakeAValue()
{
    return false;
}
    
void DisplayGreyscaleTopographyAsWhite::ProcessArgument(const char * /*argument[]*/)
{
    displayGreyscaleTopographyAsWhite = true;
}
