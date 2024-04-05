#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

void appliquerTraitement(int numsig)
{
    printf(" Ctrl-C/SIGINT reçu par le processus de n° %d\n",getpid());
}

int main(int argc, char  *argv[])
{
    /*Cette partie est pour l'exo2b*/
    execlp("../exercice2/boucler", "boucler",argv[1],argv[2],(char *)NULL);



    pid_t monPid=getpid();
    struct sigaction action;
    sigemptyset(&action.sa_mask);
    action.sa_flags=0;
    action.sa_handler=appliquerTraitement;
    sigaction(SIGINT,&action,NULL);


    time_t temps;
    struct tm info_temps;
    char date[80];

    while(1) 
    {
        time(&temps);
        localtime_r(&temps,&info_temps);
        strftime(date,sizeof(date),"%a %b %d %H:%M:%S %Y",&info_temps);
        printf("je suis le processus  %d %s\n",monPid, date);
        sleep(1);
    }

    return 0;
}
