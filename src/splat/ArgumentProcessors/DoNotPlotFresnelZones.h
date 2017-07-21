#ifndef DoNotPlotFresnelZones_h
#define DoNotPlotFresnelZones_h

#include "ArgumentProcessor.h"

class DoNotPlotFresnelZones : ArgumentProcessor
{
public:
    DoNotPlotFresnelZones(bool & doNotPlotFresnelZones);
    ~DoNotPlotFresnelZones();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    bool & plotFresnelZones;
};
#endif
