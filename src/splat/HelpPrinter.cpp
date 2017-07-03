#include "HelpPrinter.h"

#include "SharedConsts.h"

#include <stdio.h>
#include <cstring>


void HelpPrinter::PrintHelpMessage(int maxpages)
{
    fprintf(stdout,"\n\t\t --==[ %s v%s Available Options... ]==--\n\n",splat_name, splat_version);
        
    fprintf(stdout,"       -t txsite(s).qth (max of 4 with -c, max of 30 with -L)\n");
    fprintf(stdout,"       -r rxsite.qth\n");
    fprintf(stdout,"       -c plot LOS coverage of TX(s) with an RX antenna at X feet/meters AGL\n");
    fprintf(stdout,"       -L plot path loss map of TX based on an RX at X feet/meters AGL\n");
    fprintf(stdout,"       -s filename(s) of city/site file(s) to import (5 max)\n");
    fprintf(stdout,"       -b filename(s) of cartographic boundary file(s) to import (5 max)\n");
    fprintf(stdout,"       -p filename of terrain profile graph to plot\n");
    fprintf(stdout,"       -e filename of terrain elevation graph to plot\n");
    fprintf(stdout,"       -h filename of terrain height graph to plot\n");
    fprintf(stdout,"       -H filename of normalized terrain height graph to plot\n");
    fprintf(stdout,"       -l filename of path loss graph to plot\n");
    fprintf(stdout,"       -o filename of topographic map to generate (.ppm)\n");
    fprintf(stdout,"       -u filename of user-defined terrain file to import\n");
    fprintf(stdout,"       -d sdf file directory path (overrides path in ~/.splat_path file)\n");
    fprintf(stdout,"       -m earth radius multiplier\n");
    fprintf(stdout,"       -n do not plot LOS paths in .ppm maps\n");
    fprintf(stdout,"       -N do not produce unnecessary site or obstruction reports\n");
    fprintf(stdout,"       -f frequency for Fresnel zone calculation (MHz)\n");
    fprintf(stdout,"       -R modify default range for -c or -L (miles/kilometers)\n");
    fprintf(stdout,"      -sc display smooth rather than quantized contour levels\n");
    fprintf(stdout,"      -db threshold beyond which contours will not be displayed\n");
    fprintf(stdout,"      -nf do not plot Fresnel zones in height plots\n");
    fprintf(stdout,"      -fz Fresnel zone clearance percentage (default = 60)\n");
    fprintf(stdout,"      -gc ground clutter height (feet/meters)\n");
    fprintf(stdout,"     -ngs display greyscale topography as white in .ppm files\n");
    fprintf(stdout,"     -erp override ERP in .lrp file (Watts)\n");
    fprintf(stdout,"     -ano name of alphanumeric output file\n");
    fprintf(stdout,"     -ani name of alphanumeric input file\n");
    fprintf(stdout,"     -udt name of user defined terrain input file\n");
    fprintf(stdout,"     -kml generate Google Earth (.kml) compatible output\n");
    fprintf(stdout,"     -geo generate an Xastir .geo georeference file (with .ppm output)\n");
    fprintf(stdout,"     -dbm plot signal power level contours rather than field strength\n");
    fprintf(stdout,"     -log copy command line string to this output file\n");
    fprintf(stdout,"   -gpsav preserve gnuplot temporary working files after SPLAT! execution\n");
    fprintf(stdout,"  -metric employ metric rather than imperial units for all user I/O\n");
    fprintf(stdout,"  -olditm invoke Longley-Rice rather than the default ITWOM model\n");
    fprintf(stdout,"-maxpages [%d] Maximum Analysis Region capability: 1, 4, 9, 16, 25, 36, 49, 64 \n", maxpages);
    fprintf(stdout,"      -hd Enable HD mode.");
    fprintf(stdout,"\n");
    fprintf(stdout,"If that flew by too fast, consider piping the output through 'less':\n");
    
    fprintf(stdout,"\n\tsplat | less\n\n");
        
    fprintf(stdout,"Type 'man splat', or see the documentation for more details.\n\n");
    fflush(stdout);
}

bool HelpPrinter::ShouldHelpBePrinted(int argc, const char * argv[])
{
    if (argc==1 || strcmp(argv[1],"--help") == 0)
    {
        return true;
    }
    
    return false;
}
