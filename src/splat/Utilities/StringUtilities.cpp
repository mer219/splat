#include "StringUtilities.h"

#include <cstring>

void StringUtilities::StripCarriageReturnAndLineFeed(char * text)
{
    size_t nameSize = strlen(text);
    for (int characterNumber = 0; characterNumber < nameSize; characterNumber++)
    {
        if(IsCarriageReturn(text[characterNumber]) ||
            IsLineFeed(text[characterNumber]) ||
            IsNullCharacter(text[characterNumber]))
	{
            text[characterNumber] = 0;
	    break;
	}
    }
}

bool StringUtilities::IsCarriageReturn(char character)
{
   return character == 13;
}

bool StringUtilities::IsLineFeed(char character)
{
   return character == 10;
}

bool StringUtilities::IsNewLine(char character)
{
    return (IsLineFeed(character) || IsCarriageReturn(character));
}

bool StringUtilities::IsNullCharacter(char character)
{
    return character == 0;
}

bool StringUtilities::IsSpace(char character)
{
    return character == 32;
}

void StringUtilities::StripLeadingAndTrailingWhitespace(char * inputString)
{
    size_t stringLength = strlen(inputString);

    char stringCopy[20];
    int copyIndex = 0;
    for (int characterIndex = 0; characterIndex < stringLength && characterIndex < 18; characterIndex++)
    {
        if ((!IsSpace(inputString[characterIndex]) && !IsNewLine(inputString[characterIndex])) 
            || (IsSpace(inputString[characterIndex]) && !IsSpace(inputString[characterIndex + 1])
                && !IsNewLine(inputString[characterIndex + 1]) && copyIndex != 0))
        {
            stringCopy[copyIndex] = inputString[characterIndex];
	    copyIndex++;
	}	 
    }

    stringCopy[copyIndex] = 0;

    strcpy(inputString, stringCopy);
}
