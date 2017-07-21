#include "GenerateXastirGeoreferenceFile.h"

#include <cstring>

GenerateXastirGeoreferenceFile::GenerateXastirGeoreferenceFile(bool & generateXastirFile) :
    generateXastirFile(generateXastirFile)
{
}

GenerateXastirGeoreferenceFile::~GenerateXastirGeoreferenceFile()
{
}

bool GenerateXastirGeoreferenceFile::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-geo") == 0;
}

void GenerateXastirGeoreferenceFile::ProcessArgument()
{
    generateXastirFile = true;
}
