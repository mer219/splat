#include "UseLongleyRiceModel.h"

#include "Arguments.h"

#include <cstring>

UseLongleyRiceModel::UseLongleyRiceModel(bool & useLongleyRice) :
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

void UseLongleyRiceModel::ProcessArgument()
{
    useLongleyRice = true;
}
