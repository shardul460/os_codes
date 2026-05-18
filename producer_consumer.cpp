#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t e, full;
pthread_mutex_t mutex;

void* producer(void* arg) {
    sem_wait(&e);
    pthread_mutex_lock(&mutex);

    cout << "Produced Item" << endl;
    sleep(1);

    pthread_mutex_unlock(&mutex);
    sem_post(&full);

    return NULL;
}

void* consumer(void* arg) {
    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    cout << "Consumed Item" << endl;
    sleep(1);

    pthread_mutex_unlock(&mutex);
    sem_post(&e);

    return NULL;
}

int main() {
    pthread_t p, c;

    sem_init(&e, 0, 5);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&e);
    sem_destroy(&full);

    return 0;
}