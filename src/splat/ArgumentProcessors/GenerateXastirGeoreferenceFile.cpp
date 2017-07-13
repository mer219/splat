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

bool GenerateXastirGeoreferenceFile::DoesThisOptionTakeAValue()
{
    return false;
}
    
void GenerateXastirGeoreferenceFile::ProcessArgument(const char * /*argument[]*/)
{
    generateXastirFile = true;
}
