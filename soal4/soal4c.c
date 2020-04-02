#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int fd1[2];
    pid_t p,pp;

    if (pipe(fd1)==-1){
        fprintf(stderr, "Pipe Failed" );
        return 1;
    }
    p = fork();

    if (p < 0){
        fprintf(stderr, "fork Failed" );
        return 1;
    }

    else if (p > 0){
        close(1);
        dup(fd1[1]);
        close(fd1[0]);
        execlp("ls","ls",NULL);
    }
    else{
        wait(NULL);
        close(0);
        dup(fd1[0]);
        close(fd1[1]);
        execlp("wc","wc", "-l", NULL);
    }
}
