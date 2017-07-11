#ifndef StringUtilities_h
#define StringUtilities_h

class StringUtilities
{
public:
    void StripCarriageReturnAndLineFeed(char * text);
    bool IsCarriageReturn(char character);
    bool IsLineFeed(char character);
    bool IsNewLine(char character);
    bool IsNullCharacter(char character);
    bool IsSpace(char character);
    void StripLeadingAndTrailingWhitespace(char * inputString);
};

#endif
