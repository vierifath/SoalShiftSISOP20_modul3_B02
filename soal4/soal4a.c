#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //library thread

pthread_t tid1, tid2, tid3, tid4, tid5;
int status,status2;
int A[5][3], B[3][6], C[5][6];

void* input(void *arg){
    status = 0;
    printf("Masukkan matrix a (4x2) dan b (2x5): ");
    for(int j = 0; j < 4; j++){
        for (int k = 0; k< 2; k++){
            if (A[j][k]>= 1 || A[j][k] <=20)
            scanf("%d", &A[j][k]);
        }
    }
    for(int j = 0; j < 2; j++){
        for (int k = 0; k< 5; k++){
            if (A[j][k]>= 1 || A[j][k] <=20)
            scanf("%d", &B[j][k]);
        }
    }
    status = 1;
    return NULL;
}

void* calculate1(void *arg){
    status2=0;
    while(status!=1)
    {

    }
    for (int i = 0; i < 4; i++){
        C[i][0] = A[i][0]*B[0][0] + A[i][1]*B[1][0];
    }
    return NULL;
}

void* calculate2(void *arg){
    while(status!=1)
    {

    }
    for (int i = 0; i < 4; i++){
        C[i][1] = A[i][0]*B[0][1] + A[i][1]*B[1][1];
    }
    return NULL;
}

void* calculate3(void *arg){
    while(status!=1)
    {

    }
    for (int i = 0; i < 4; i++){
        C[i][2] = A[i][0]*B[0][2] + A[i][1]*B[1][2];
    }
    status2=1;
    return NULL;
}

void* calculate4(void *arg){
    while(status!=1)
    {

    }
    for (int i = 0; i < 4; i++){
        C[i][2] = A[i][0]*B[0][2] + A[i][1]*B[1][2];
    }
    status2=1;
    return NULL;
}


void* output(void *arg){
    while(status2!=1)
    {

    }
    for(int j = 0; j < 4; j++){
        for (int k = 0; k< 5; k++){
            printf("%d ", C[j][k]);
        }
        printf("\n");
    }
}

int main(void){
    pthread_create(&(tid1), NULL, input, NULL);
    pthread_create(&(tid2), NULL, calculate1, NULL);
    pthread_create(&(tid3), NULL, calculate2, NULL);
    pthread_create(&(tid4), NULL, calculate3, NULL);
    pthread_create(&(tid4), NULL, calculate4, NULL);
    pthread_create(&(tid5), NULL, output, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    pthread_join(tid5, NULL);
    return 0;
}
