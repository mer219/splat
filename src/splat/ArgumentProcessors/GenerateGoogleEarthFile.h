#ifndef GenerateGoogleEarthFile_h
#define GenerateGoogleEarthFile_h

#include "ArgumentProcessor.h"

class GenerateGoogleEarthFile : ArgumentProcessor
{
public:
    GenerateGoogleEarthFile(bool & generateGoogleEarthFile);
    ~GenerateGoogleEarthFile();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    bool & generateGoogleEarthFile;
};
#endif
