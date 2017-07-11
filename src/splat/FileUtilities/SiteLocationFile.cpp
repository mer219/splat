#include "SiteLocationFile.h"

#include "../include/Site.h"
#include "../Utilities/StringUtilities.h"

#include <cstdio>
#include <cstring>
#include <cmath>

SiteLocationFile::SiteLocationFile(StringUtilities stringUtilities) :
    stringUtilities(stringUtilities)
{
}

SiteLocationFile::~SiteLocationFile()
{
}

Site * SiteLocationFile::ReadFile(char * fileName)
{
	/* This function reads SPLAT! .qth (site location) files.
	   The latitude and longitude may be expressed either in
	   decimal degrees, or in degree, minute, second format.
	   Antenna height is assumed to be expressed in feet above
	   ground level (AGL), unless followed by the letter 'M',
	   or 'm', or by the word "meters" or "Meters", in which
	   case meters is assumed, and is handled accordingly. */

    Site * site = new Site();

    if(IsFileNameValid(fileName))
    {
        if(!DoesFileNameHaveExtension(fileName))
	{
            AppendExtension(fileName);
	}

        FILE * fileDescriptor = fopen(fileName, "r");

        if (fileDescriptor != NULL)
        {
            /* Site Name */
            fgets(site->name, 49, fileDescriptor);

            /* Strip <CR> and/or <LF> from end of site name */
            stringUtilities.StripCarriageReturnAndLineFeed(site->name);

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
	    stringUtilities.StripCarriageReturnAndLineFeed(temp);

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
                site->altitude *= 3.28084;
            }
            else
            {
                sscanf(temp,"%f",&site->altitude);
            }
            
            strcpy(site->fileName, fileName);
	}
    }

    return site;
}

bool SiteLocationFile::DoesStringContainM(char * inputString, int& mCharacterIndex)
{
    const char ASCII_M = 77;
    const char ASCII_m = 109;
    for (int characterIndex = 0; characterIndex <48; characterIndex++)
    {
        if(inputString[characterIndex] == ASCII_M || inputString[characterIndex] == ASCII_m)
        {
            mCharacterIndex = characterIndex;
            return true;
        }
	if(stringUtilities.IsNullCharacter(inputString[characterIndex]))
	{
            return false;
	}
    }
    return false;
}

bool SiteLocationFile::IsFileNameValid(char * fileName)
{
    size_t nameLength = strlen(fileName);

    if(DoesFileNameHaveExtension(fileName))
    {
        if (nameLength > 249)
	{
            return false; 
	}
    }
    return true;
}

bool SiteLocationFile::DoesFileNameHaveExtension(char * fileName)
{ 
    size_t nameLength = strlen(fileName);

    return (fileName[nameLength-3] != 'q' || fileName[nameLength-2] != 't' || fileName[nameLength-1] != 'h');
}

void SiteLocationFile::AppendExtension(char * fileName)
{
    strncat(fileName, ".qth\0", 5);
}

double SiteLocationFile::ConvertBearingStringToDouble(char * bearingString)
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

    stringUtilities.StripLeadingAndTrailingWhitespace(bearingString);

    int bearingStringLength = strlen(bearingString);

    int numberOfSpaces = 0;

    for (int characterIndex = 0; characterIndex < bearingStringLength; characterIndex++)
    {
        if (stringUtilities.IsSpace(bearingString[characterIndex]))
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
	double minutes = 0;
	double seconds = 0;

        sscanf(bearingString, "%lf %lf %lf", &degrees, &minutes, &seconds);

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
