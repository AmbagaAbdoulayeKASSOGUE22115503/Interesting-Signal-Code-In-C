#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
//Déclaration des variables globales
pid_t pidFils;


void appliquerTraitement(int numsig)
{
    printf(" Ctrl-C/SIGINT reçu par le processus de n° %d\n",pidFils);
}

void afficher()
{
    time_t temps;
    struct tm info_temps;
    char date[80];

    while(1)
    {
        time(&temps);
        localtime_r(&temps,&info_temps);
        strftime(date,sizeof(date),"%a %b %d %H:%M:%S %Y",&info_temps);
        printf("je suis le processus %d %s\n",pidFils, date);
        sleep(1);
    }
}


int main(void)
{
    struct sigaction actionPere;
    sigemptyset(&actionPere.sa_mask);
    actionPere.sa_flags=0;
    actionPere.sa_handler=SIG_IGN;
    sigaction(SIGINT,&actionPere,NULL);

    pid_t  pid;
    switch (pid = fork())  //On crée un enfant
    {
        case -1:
            perror("fork");
            exit(1);
        case 0: 
            pidFils=getpid();
            struct sigaction action;
            sigemptyset(&action.sa_mask);
            action.sa_flags=0;
            action.sa_handler=appliquerTraitement;
            sigaction(SIGINT,&action,NULL);
            afficher();
            exit(0);
        default: 
            wait(NULL);
            exit(0);
    }

    return 0;
}
