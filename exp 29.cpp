#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t customer,barber,mutex;
int waiting=0;
void* bar(void* a){
    while(1){
        sem_wait(&customer);
        sem_wait(&mutex); waiting--; sem_post(&mutex);
        printf("Barber cutting hair\n");
        sleep(1);
        sem_post(&barber);
    }
}
void* cust(void* a){
    sem_wait(&mutex); waiting++; printf("Customer arrived\n"); sem_post(&mutex);
    sem_post(&customer); sem_wait(&barber); printf("Customer served\n");
    return NULL;
}
int main(){
    pthread_t b,c1,c2;
    sem_init(&customer,0,0); sem_init(&barber,0,0); sem_init(&mutex,0,1);
    pthread_create(&b,NULL,bar,NULL);
    pthread_create(&c1,NULL,cust,NULL);
    pthread_create(&c2,NULL,cust,NULL);
    pthread_join(c1,NULL); pthread_join(c2,NULL);
    return 0;
}
