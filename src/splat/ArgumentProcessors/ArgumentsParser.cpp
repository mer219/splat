#include "ArgumentsParser.h"

#include "ArgumentProcessor.h"

#include <stdexcept>

ArgumentsParser::ArgumentsParser(std::vector<ArgumentProcessor*>& argumentProcessors) :
    argumentProcessors(argumentProcessors)
{
}

void ArgumentsParser::ProcessArguments(int argc, const char * argv[])
{
    int numberOfArguments = argc - 1; //the first argument is the application name

    for (int argumentIndex = 1; argumentIndex <= numberOfArguments; argumentIndex++)
    {
       for (std::vector<ArgumentProcessor*>::iterator argumentProcessor = argumentProcessors.begin(); argumentProcessor != argumentProcessors.end(); argumentProcessor++)
       {
           if((*argumentProcessor)->ArgumentBelongsToThisProcessor(argv[argumentIndex]))
           {
	       if((*argumentProcessor)->DoesThisOptionTakeAValue())
               {
                   argumentIndex += 1;
		   if(argumentIndex > numberOfArguments)
                   {
                       throw std::invalid_argument("Insufficient Number of Arguments");
                   }
               }

	       (*argumentProcessor)->ProcessArgument(argv[argumentIndex]);
	       break;
           }
       }
    }
}
/*	       
        if (strcmp(argv[x],"-sc")==0)
            smooth_contours=1;
        
        if (strcmp(argv[x],"-olditm")==0)
            olditm=1;
        
        if (strcmp(argv[x],"-N")==0)
        {
            nolospath=1;
            nositereports=1;
        }
        
        if (strcmp(argv[x],"-d")==0)
        {
            z=x+1;
            
            if (z<=y && argv[z][0] && argv[z][0]!='-')
                strncpy(sdf_path,argv[z],253);
        }
        
        if (strcmp(argv[x],"-t")==0)
        {
            // Read Transmitter Location 
            
            z=x+1;
            
            while (z<=y && argv[z][0] && argv[z][0]!='-' && txsites<30)
            {
                strncpy(txfile,argv[z],253);
                tx_site[txsites]=LoadQTH(txfile);
                txsites++;
                z++;
            }
            
            z--;
        }
        
        if (strcmp(argv[x],"-L")==0)
        {
            z=x+1;
            
            if (z<=y && argv[z][0] && argv[z][0]!='-')
            {
                sscanf(argv[z],"%lf",&altitudeLR);
                map=1;
                LRmap=1;
                area_mode=1;
                
                if (coverage)
                    fprintf(stdout,"c and L are exclusive options, ignoring L.\n");
            }
        }
        
        if (strcmp(argv[x],"-l")==0)
        {
            z=x+1;
            
            if (z<=y && argv[z][0] && argv[z][0]!='-')
            {
                strncpy(longley_file,argv[z],253);
                longley_plot=1;
                pt2pt_mode=1;
            }
        }
        
        if (strcmp(argv[x],"-r")==0)
        {
            // Read Receiver Location 
            
            z=x+1;
            
            if (z<=y && argv[z][0] && argv[z][0]!='-')
            {
                strncpy(rxfile,argv[z],253);
                rx_site=LoadQTH(rxfile);
                rxsite=1;
                pt2pt_mode=1;
            }
        }
        
        if (strcmp(argv[x],"-s")==0)
        {
            // Read city file(s) 
            
            z=x+1;
            
            while (z<=y && argv[z][0] && argv[z][0]!='-' && cities<5)
            {
                strncpy(city_file[cities],argv[z],253);
                cities++;
                z++;
            }
            
            z--;
        }
        
        if (strcmp(argv[x],"-b")==0)
        {
            // Read Boundary File(s) 
            
            z=x+1;
            
            while (z<=y && argv[z][0] && argv[z][0]!='-' && bfs<5)
            {
                strncpy(boundary_file[bfs],argv[z],253);
                bfs++;
                z++;
            }
            
            z--;
        }
        
        if (strcmp(argv[x],"-f")==0)
        {
            z=x+1;
            
            if (z<=y && argv[z][0] && argv[z][0]!='-')
            {
                sscanf(argv[z],"%lf",&forced_freq);
                
                if (forced_freq<20.0)
                    forced_freq=0.0;
                
                if (forced_freq>20.0e3)
                    forced_freq=20.0e3;
            }
        }
        
        if (strcmp(argv[x],"-erp")==0)
        {
            z=x+1;
            
            if (z<=y && argv[z][0] && argv[z][0]!='-')
            {
                sscanf(argv[z],"%lf",&forced_erp);
                
                if (forced_erp<0.0)
                    forced_erp=-1.0;
            }
        }
        
        if (strcmp(argv[x],"-ano")==0)
        {
            z=x+1;
            
            if (z<=y && argv[z][0] && argv[z][0]!='-')
                strncpy(ano_filename,argv[z],253);
        }
        
        if (strcmp(argv[x],"-ani")==0)
        {
            z=x+1;
            
            if (z<=y && argv[z][0] && argv[z][0]!='-')
                strncpy(ani_filename,argv[z],253);
        }
        
        if (strcmp(argv[x],"-maxpages")==0)
        {
            z=x+1;
            
            if (z<=y && argv[z][0] && argv[z][0]!='-')
            {
                strncpy(maxpages_str,argv[z],sizeof(maxpages_str));
                maxpages_str[sizeof(maxpages_str) - 1] = '\0';
                if (sscanf(maxpages_str, "%d", &maxpages) != 1)
                {
                    fprintf(stderr,"\n%c*** ERROR: Could not parse maxpages: %s\n\n", 7, maxpages_str);
                    exit (-1);
                }
            }
        }
        
        if (strcmp(argv[x],"-hd")==0)
        {
            hd_mode = true;
        }
    }
}
*/

