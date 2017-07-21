#ifndef Arguments_h
#define Arguments_h

class Arguments
{
public:
    ~Arguments(){};
    virtual char * ProcessNextArgument() = 0;
    virtual void BackUpOneArgument() = 0;
    virtual bool AreThereUnprocessedArguments() = 0;
};
#endif
