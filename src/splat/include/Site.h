#ifndef Site_h
#define Site_h

struct Site 
{
    Site()
    {
        latitude = 91;
	longitude = 361;
	altitude = 0;
	name[0] = 0;
	fileName[0] = 0;
    }

    double latitude;
    double longitude;
    float altitude;
    char name[50];
    char fileName[255];
};

#endif
