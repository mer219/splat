#include "DisplayGreyscaleTopographyAsWhite.h"

#include <cstring>

DisplayGreyscaleTopographyAsWhite::DisplayGreyscaleTopographyAsWhite(bool & displayGreyscaleTopographyAsWhite) :
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

void DisplayGreyscaleTopographyAsWhite::ProcessArgument()
{
    displayGreyscaleTopographyAsWhite = true;
}
