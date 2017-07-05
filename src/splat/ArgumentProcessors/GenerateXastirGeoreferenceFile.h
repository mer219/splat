#ifndef GenerateXastirGeoreferenceFile_h
#define GenerateXastirGeoreferenceFile_h

#include "ArgumentProcessor.h"

class GenerateXastirGeoreferenceFile : ArgumentProcessor
{
public:
    GenerateXastirGeoreferenceFile(bool& generateXastirFile);
    ~GenerateXastirGeoreferenceFile();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    bool& generateXastirFile;
};
#endif
