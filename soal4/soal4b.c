#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

pthread_t tid[20];
int status,x,y;
int C[4][5];
int D[4][5];

void *fact(void *arg){
    int c,f=1;
    int n = (int *)arg;
    for (c = 1; c <= n; c++)
        f = f * c;
    printf("%d\n", f);
}


int main()
{
    for(int j = 0; j < 4; j++){
        for (int k = 0; k< 5; k++){
            key_t key = 1234;
            int *value;

            int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
            value = shmat(shmid, NULL, 0);
            C[j][k] = *value;
            puts("bor");
            sleep(3);
        }
    }
    int cnt=0;
    for(int j = 0; j < 4; j++){
        for (int k = 0; k< 5; k++){
            printf("%d ", C[j][k]);
            //fak gw bingung gimana bikin thread mecah per elemen wat faktorial
            //pthread_create(&(tid[cnt++]),NULL,&fact,(void*)C[j][k]);
        }
    printf("\n");
    }
    // for(int j = 0; j < 4; j++){
    // for (int k = 0; k< 5; k++){
    // printf("%d ", D[j][k]);
    // }
    // printf("\n");
    // }
}
