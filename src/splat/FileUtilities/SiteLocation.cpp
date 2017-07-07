#include "SiteLocation.h"

#include "../include/Site.h"

Site * SiteLocationFile::ReadFile(char * filename)
{
	/* This function reads SPLAT! .qth (site location) files.
	   The latitude and longitude may be expressed either in
	   decimal degrees, or in degree, minute, second format.
	   Antenna height is assumed to be expressed in feet above
	   ground level (AGL), unless followed by the letter 'M',
	   or 'm', or by the word "meters" or "Meters", in which
	   case meters is assumed, and is handled accordingly. */

    if(IsFileNameValid(fileName))
    {
        if(!DoesFileNameHaveExtension(fileName))
	{
            AppendExtension(fileName);
	}

        FILE * fileDescriptor = fopen(fileName, "r");

        if (fd != NULL)
        {
            Site * site = new Site();

            /* Site Name */
            fgets(site->name, 49, fd);

            /* Strip <CR> and/or <LF> from end of site name */
            StripCarriageReturnAndLineFeed(site->name);

	    char temp[50];

            /* Site Latitude */
            fgets(temp, 49, fileDescriptor);
            site->latitude = ConvertBearingStringToDouble(temp);

            /* Site Longitude */
            site->longitude = ConvertBearingStringToDouble(temp);

            if (site->longitude < 0.0)
                site->longitude += 360.0;

            /* Antenna Height */
            fgets(temp, 49, fileDescriptor);
            fclose(fileDescriptor);

            /* Remove <CR> and/or <LF> from antenna height string */
	    StripCarriageReturnAndLineFeed(temp);

		/* Antenna height may either be in feet or meters.
		   If the letter 'M' or 'm' is discovered in
		   the string, then this is an indication that
		   the value given is expressed in meters, and
		   must be converted to feet before exiting. */

            int mCharacterIndex = 0;
            if (DoesStringContainM(temp, mCharacterIndex))
            {
                temp[mCharacterIndex] = 0;
                sscanf(temp,"%f",&site->altitude);
                site->altitued *= 3.28084;
            }
            else
            {
                sscanf(temp,"%f",&site->altitude);
            }
            
            strcpy(site->fileName, fileName);
	}

	return site;
}

bool SiteLocation::DoesStringContainM(char * inputString, int& mCharacterIndex)
{
    for (characterIndex = 0; characterIndex <48; characterIndex++)
    {
        if(inputString[characterIndex] == "M" || inputString[characterIndex] == "m")
        {
            mCharacterIndex = characterIndex;
            return true;
        }
	if(IsNullCharacter(inputString[characterIndex]))
	{
            return false;
	}
    }
    return false;
}

bool SiteLocation::IsFilenameValid(char * fileName)
{
    size_t nameLength = strlen(filename);

    if(DoesFileNameHaveExtension(fileName)
    {
        if (nameLength > 249)
	{
            return false; 
	}
    }
    return true;
}

bool SiteLocation::DoesFileNameHaveExtension(char * fileName)
{ 
    size_t nameLength = strlen(filename);

    return (filename[nameLength-3] != 'q' || fileName[nameLength-2] != 't' || fileName[nameLength-1] != 'h');
}

void SiteLocation::AppendExtension(char * fileName)
{
    strncat(fileName, ".qth\0", 5);
}

double ConvertBearingStringToDouble(char * bearingString)
{
	/* This function takes numeric input in the form of a character
	   string, and returns an equivalent bearing in degrees as a
	   decimal number (double).  The input may either be expressed
	   in decimal format (40.139722) or degree, minute, second
	   format (40 08 23).  This function also safely handles
	   extra spaces found either leading, trailing, or
	   embedded within the numbers expressed in the
	   input string.  Decimal seconds are permitted. */
 

	/* Copy "input" to "string", and ignore any extra
	   spaces that might be present in the process. */


    /* Count number of spaces in the clean string. */

    StripLeadingAndTrailingWhitespace(bearingString);

    bearingStringLength = strlen(bearingSTring);

    int numberOfSpace = 0;

    for (int characterIndex = 0; characterIndex < bearingStringLength; characterIndex++)
    {
        if (IsSpace(bearingString[characterIndex])
        {
            numberOfSpaces++;
        }
    }

    double bearing = 0;

    if (numberOfSpaces == 0)  /* Decimal Format (40.139722) */
    {
        sscanf(bearingString, "%lf", &bearing);
    }

    if (numberOfSpaces == 2)  /* Degree, Minute, Second Format (40 08 23.xx) */
    {
        double degrees = 0;
	double minuets = 0;
	double seconds = 0;

        sscanf(bearingString, "%d %d %lf", &degrees, &minutes, &seconds);

        bearing = fabs(degrees);
        bearing += fabs(minutes / 60.0);
        bearing += fabs(seconds / 3600.0);

        if ((degrees < 0) || (minutes < 0) || (seconds < 0))
            bearing=-bearing;
    }

    /* Anything else returns a 0.0 */

    if (bearing>360.0 || bearing<-360.0)
        bearing=0.0;

    return bearing;
}
