#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if(argc<3)
    {
        fprintf(stderr,"nb argc invalide");
        exit(1);
    }
    int NBS=atoi(argv[1]);
    int NBF=atoi(argv[2]);
    time_t temps;
    struct tm info_temps;
    char date[80];

    for(int i=0;i<NBF;++i)
    {
        time(&temps);
        localtime_r(&temps,&info_temps);
        strftime(date,sizeof(date),"%a %b %d %H:%M:%S %Y",&info_temps);
        printf("je suis le processus %d, il est %s\n",getpid(),date);
        sleep(NBS);
    }

    return 0;
}
