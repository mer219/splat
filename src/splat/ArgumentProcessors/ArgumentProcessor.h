#ifndef ArgumentProcessor_h
#define ArgumentProcessor_h

class ArgumentProcessor
{
public:
    virtual ~ArgumentProcessor(){};

    virtual bool ArgumentBelongsToThisProcessor(const char * argument) = 0;
    virtual bool DoesThisOptionTakeAValue() = 0;
    virtual void ProcessArgument(const char argument[]) = 0;
};
#endif
