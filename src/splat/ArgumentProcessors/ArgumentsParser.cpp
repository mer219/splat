#include "ArgumentsParser.h"

#include "ArgumentProcessor.h"

#include "Arguments.h"

#include <stdexcept>

ArgumentsParser::ArgumentsParser(Arguments & arguments, std::vector<ArgumentProcessor*>& argumentProcessors) :
    arguments(arguments),
    argumentProcessors(argumentProcessors)
{
}

void ArgumentsParser::ProcessArguments()
{
    while(arguments.AreThereUnprocessedArguments())
    {
        char * argument = arguments.ProcessNextArgument();
        for (std::vector<ArgumentProcessor*>::iterator argumentProcessor = argumentProcessors.begin(); argumentProcessor != argumentProcessors.end(); argumentProcessor++)
        {
            if((*argumentProcessor)->ArgumentBelongsToThisProcessor(argument))
            {
	            (*argumentProcessor)->ProcessArgument(argument);
	            break;
            }
        }
    }
}
/*	       
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

