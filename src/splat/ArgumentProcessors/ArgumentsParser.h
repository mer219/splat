#ifndef ArgumentsParser_h
#define ArgumentsParser_h

#include <vector>

class ArgumentProcessor;
class Arguments;

class ArgumentsParser
{
public:
    ArgumentsParser(Arguments & arguments, std::vector<ArgumentProcessor *> & argumentProcessors);
    void ProcessArguments();

private:
    Arguments & arguments;
    std::vector<ArgumentProcessor *> & argumentProcessors;
};

#endif
