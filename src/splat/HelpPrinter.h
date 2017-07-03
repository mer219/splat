#ifndef HelpPrinter_h
#define HelpPrinter_h

class HelpPrinter
{
    public:
        void PrintHelpMessage(int maxpages);
        bool ShouldHelpBePrinted(int argc, const char * argv[]);
};

#endif
