#ifndef SiteLocationFile_h
#define SiteLocationFile_h

class Site;
class StringUtilities;

class SiteLocationFile
{
public:
    SiteLocationFile(StringUtilities stringUtilities);
    ~SiteLocationFile();

    Site * ReadFile(char * filename);

private:
    bool DoesStringContainM(char * inputString, int& mCharacterIndex);
    bool IsFileNameValid(char * fileName);
    bool DoesFileNameHaveExtension(char * fileName);
    void AppendExtension(char * fileName);
    double ConvertBearingStringToDouble(char * bearingString);

    StringUtilities& stringUtilities;
};
#endif
