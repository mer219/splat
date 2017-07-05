#ifndef DoNotPlotFresnelZones_h
#define DoNotPlotFresnelZones_h

#include "ArgumentProcessor.h"

class DoNotPlotFresnelZones : ArgumentProcessor
{
public:
    DoNotPlotFresnelZones(bool& doNotPlotFresnelZones);
    ~DoNotPlotFresnelZones();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    bool DoesThisOptionTakeAValue();
    void ProcessArgument(const char argument[]);

private:
    bool& plotFresnelZones;
};
#endif
