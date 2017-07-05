#ifndef ArgumentsParser_h
#define ArgumentsParser_h

#include <vector>

class ArgumentProcessor;

class ArgumentsParser
{
public:
    ArgumentsParser(std::vector<ArgumentProcessor*>& argumentProcessors);
    void ProcessArguments(int argc, const char * argv[]);

private:
    std::vector<ArgumentProcessor*>& argumentProcessors;
};

#endif
