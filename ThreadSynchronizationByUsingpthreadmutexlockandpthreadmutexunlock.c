#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <studio.h>
#include <string.h>

pthread_t threId[2];
int coun;
pthread_mutex_t isLock;

void *trythis(void *arg){
    pthread_mutex_lock(&isLock);
    unsigned long i=0;
    coun +=1;
    printf("\n job %d has started \n ",coun);
    for(i=0;i<(0*FFFFFF);i++){
        printf("\n job %d has finished\n",coun);
    }
    pthread_mutex_unlock(&isLock);
    return NULL;
}
int main(void){
    int i=0;
    int error;
    if(pthread_mutex_init(&isLock,NULL) != 0){
        printf("\n mutex init has failed \n");
        return 1;
    }
    while(i<2){
        error=pthread_create(&(threId[i]),NULL,&trythis,NULL);
        if(error!=0){
            printf("\nThread can't be created :[%s]",strerror(error));
        }
        i++;
    }
    pthread_join(threId[0],NULL);
    pthread_join(threId[1],NULL);
    pthread_mutex_destroy(&isLock);
    return 0;
}

//OUTPUT:-
//job 1 started
//job 2 finished
//job 2 started
//job 2 finished