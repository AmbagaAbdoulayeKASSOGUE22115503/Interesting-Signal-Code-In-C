#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    execlp("../exercice1/exo1a","exo1a",argv[1],argv[2],(char *)NULL);
    return 0;
}
