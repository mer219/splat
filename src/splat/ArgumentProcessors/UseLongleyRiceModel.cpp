#include "UseLongleyRiceModel.h"

#include <cstring>

UseLongleyRiceModel::UseLongleyRiceModel(bool& useLongleyRice) :
    useLongleyRice(useLongleyRice)
{
}

UseLongleyRiceModel::~UseLongleyRiceModel()
{
}

bool UseLongleyRiceModel::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-olditm") == 0;
}

bool UseLongleyRiceModel::DoesThisOptionTakeAValue()
{
    return false;
}
    
void UseLongleyRiceModel::ProcessArgument(const char * /*argument[]*/)
{
    useLongleyRice = true;
}
