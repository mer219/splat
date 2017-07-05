#include "GenerateGoogleEarthFile.h"

#include <cstring>

GenerateGoogleEarthFile::GenerateGoogleEarthFile(bool& generateGoogleEarthFile) :
    generateGoogleEarthFile(generateGoogleEarthFile)
{
}

GenerateGoogleEarthFile::~GenerateGoogleEarthFile()
{
}

bool GenerateGoogleEarthFile::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-kml") == 0;
}

bool GenerateGoogleEarthFile::DoesThisOptionTakeAValue()
{
    return false;
}
    
void GenerateGoogleEarthFile::ProcessArgument(const char * /*argument[]*/)
{
    generateGoogleEarthFile = true;
}
