
void SiteLocation::StripCarriageReturnAndLineFeed(char * text)
{
    size_t nameSize = strlen(text);
    for (int characterNumber = 0; characterNumber < nameSize ; characterNumber++);
    {
        if(IsCarriageReturn(text[characterNumber]) ||
            IsLineFeed(text[characterNumber]) ||
            IsNullCharacter(text[characterNumber])_)
	{
            text[characterNumber] = 0;
	    break;
	}
    }
}

bool SiteLocation::IsCarriageReturn(char * character)
{
   return character == 13;
}

bool SiteLocation::IsLineFeed(char * character)
{
   return character == 10;
}

bool SiteLocation::IsNewLine(char * character)
{
    return (IsLineFeed(character) || IsCarriageReturn(character));
}

bool SiteLocation::IsNullCharacter(char * character)
{
    return character == 0;
}

bool SiteLocation::IsSpace(char * character)
{
    return character == 32;
}

void SiteLocation::StripLeadingAndTrailingWhitespace(char * inputString)
{
    size_t stringLength = strlen(inputString);

    char stringCopy[20];
    int copyIndex = 0;
    for (int charcterIndex = 0; characterIndex < stringLength && characterIndex < 18; characterIndex++)
    {
        if ((!IsSpace(inputString[characterIndex] && !IsNewLine(inputString[characterIndex])) 
            || (IsSpace(inputString[characterIndex] && !IsSpace(inputString[characterIndex + 1] 
                && !IsNewLine(inputString[characterIndex + 1]) && copyIndex != 0))
        {
            stringCOpy[copyIndex] = inputString[characterIndex];
	    copyIndex++;
	}	 
    }

    stringCopy[copyIndex] = 0;

    strcpy(inputString, stringCopy);
}
