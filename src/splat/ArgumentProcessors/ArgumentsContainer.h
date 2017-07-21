#ifndef ArgumentsContainer_h
#define ArgumentsContainer_h

#include <vector>

class ArgumentsContainer : public Arguments
{
public:
    ArgumentsContainer(int argc, char ** argv);

    char * ProcessNextArgument();
    void BackUpOneArgument();
    bool AreThereUnprocessedArguments();

private:
    std::vector<char *> arguments;
    std::vector<char *>::interator argumentIterator;
}

#endif
