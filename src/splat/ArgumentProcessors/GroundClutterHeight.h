#ifndef GroundClutterHeight_h
#define GroundClutterHeight_h

#include "ArgumentProcessor.h"

class GroundClutterHeight : ArgumentProcessor
{
public:
    GroundClutterHeight(double& clutterHeight);
    ~GroundClutterHeight();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    double& clutterHeight;
};
#endif
