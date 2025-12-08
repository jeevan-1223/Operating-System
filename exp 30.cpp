#include <stdio.h>
#include <pthread.h>
void* task(void* arg){
    printf("Thread running\n");
    pthread_exit(NULL);
}
int main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,task,NULL);
    pthread_create(&t2,NULL,task,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    if(pthread_equal(t1,t2)) printf("Threads equal\n");
    else printf("Threads not equal\n");
    return 0;
}
