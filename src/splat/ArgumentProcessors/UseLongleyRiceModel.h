#ifndef UseLongleyRiceModel_h
#define UseLongleyRiceModel_h

#include "ArgumentProcessor.h"

class UseLongleyRiceModel : ArgumentProcessor
{
public:
    UseLongleyRiceModel(bool & useLongleyRice);
    ~UseLongleyRiceModel();

    bool ArgumentBelongsToThisProcessor(const char * argument);
    void ProcessArgument();

private:
    bool & useLongleyRice;
};
#endif
