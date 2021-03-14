#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;
    int status;

    if((pid = fork())<0)
        perror("fork hiba");
    else if(pid ==0)
        exit(7);
    if(wait(&status)!=pid)
        perror("wait hiba");
    if(WIFEEXITED(status))
        printf("Normalis befejezodes visszaadott ertek");
    return 0;
}
