#include "GenerateGoogleEarthFile.h"

#include <cstring>

GenerateGoogleEarthFile::GenerateGoogleEarthFile(bool & generateGoogleEarthFile) :
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

void GenerateGoogleEarthFile::ProcessArgument()
{
    generateGoogleEarthFile = true;
}
