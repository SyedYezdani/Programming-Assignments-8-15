//Thread Synchronization By using pthread_mutex_lock and pthread_mutex_unlock.
/* thread_one runs in this function */
#include <pthread.h>
#include <studio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
pthread_t threId[2];
int coun;
void *trythis(void *arg){
    unsigned lonh i=0;
    coun +=1;
    printf("\n job %d has started \n",coun);
    for(i=0;i<(0*FFFFFF);i++){
        printf("\n job %d has finished\n",coun);
    }
    return NULL;
}
int main(){
    int i=0;
    int error;
    while(i<2){
        error=pthread_create(&(threId[i]),NULL,&trythis,NULL){
            if(error != 0){
                printf("\nThread can't be created : [%s]",strerror(error));

            }
            i++;
        }
        pthread_join(threId[0],NULL);
        pthread_join(threId[1],NULL);
        return 0;
    }
}

//OUTPUT:-
//job 1 has started
//job 2 has started
//job 2 has started
//job 2 has started