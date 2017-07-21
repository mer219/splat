#ifndef GroundClutterHeight_h
#define GroundClutterHeight_h

#include "ArgumentProcessor.h"

class Arguments;

class GroundClutterHeight : ArgumentProcessor
{
public:
    GroundClutterHeight(Arguments & arguments, double & clutterHeight);
    ~GroundClutterHeight();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    Arguments & arguments;
    double & clutterHeight;
};
#endif
