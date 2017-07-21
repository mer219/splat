#include "LongleyPlotOutputFileName.h"

#include "Arguments.h"

#include <cstring>
#include <stdexcept>

LongleyPlotOutputFileName::LongleyPlotOutputFileName(Arguments & arguments, char * longleyFileName, bool & generateLongleyPlot) :
    arguments(arguments),
    longleyFileName(longleyFileName),
    generateLongleyPlot(generateLongleyPlot)
{
}

LongleyPlotOutputFileName::~LongleyPlotOutputFileName()
{
}

bool LongleyPlotOutputFileName::ArgumentBelongsToThisProcessor(const char * argument)
{
    return strcmp(argument, "-l") == 0;
}

void LongleyPlotOutputFileName::ProcessArgument()
{
    if(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
        if (argument[0] && argument[0] != '-')
        {
            strncpy(longleyFileName, argument, 253);
            generateLongleyPlot = 1;
        }
        else
        {
            throw std::invalid_argument("Invalid Longely Plot Output File Name");
        }
    }
    else
    {
        throw std::invalid_argument("Not enough arguments");
    }
}
