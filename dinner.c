#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
sem_t chopstick[5];
void eat(int ph){
    printf("\n%i Eating\n",ph);
}
void * philo(void *ph){
    int p=*(int *)ph;
    printf("\ntries left %i\n",p);
    sem_wait(&chopstick[p]);
    printf("\npicked left %i\n",p);
    printf("\ntries right %i\n",p);
    sem_wait(&chopstick[(p+1)%5]);
    printf("\npicked right %i\n",p);
    eat(p);
    //sleep(20);
    sem_post(&chopstick[p]);
    printf("\nreturn left %i\n",p);
    sem_post(&chopstick[(p+1)%5]);
    printf("\nreturn right %i\n",p);
}
void main(){
    pthread_t t[5];
    for(int i=0;i<5;i++){
        sem_init(&chopstick[i],0,1);
    }
    int i,n[5];
    for(i=0;i<5;i++){
            n[i]=i;
        pthread_create(&t[i],NULL,philo,(void *)&n[i]);
    }
    for(i=0;i<5;i++){
        pthread_join(t[i],NULL);
    }
}
