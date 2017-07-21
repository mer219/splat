#include "ArgumentsContainer.h"

ArgumentsContainer::ArgumentsContainer(int argc, char ** argv)
{
    //Argument 0 is the name of the application
    for(int argumentIndex = 1; argumentIndex < argc; argumentIndex++)
    {
        arguments.push_back(argv[argc]);
    }

    argumentIterator = arguments.begin();
}

char * ArgumentsContainer::ProcessNextArgument()
{
    return argumentIterator++;
}

void ArgumentsContainer::BackUpOneArgument()
{
    if(argumentIterator != argumentIterator.begin())
    {
        argumentIterator--;
    }
}

bool ArgumentsContainer::AreThereUnprocessedArguments()
{
    return argumentIterator != arguments.end();
}
