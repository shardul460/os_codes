#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t fork[5];

void* philosopher(void* arg) {
    int i = *((int*)arg);

    sem_wait(&fork[i]);
    sem_wait(&fork[(i + 1) % 5]);

    cout << "Philosopher " << i << " is eating\n";
    sleep(1);

    sem_post(&fork[i]);
    sem_post(&fork[(i + 1) % 5]);

    return NULL;
}

int main() {
    pthread_t p[5];
    int id[5];

    for (int i = 0; i < 5; i++)
        sem_init(&fork[i], 0, 1);

    for (int i = 0; i < 5; i++) {
        id[i] = i;
        pthread_create(&p[i], NULL, philosopher, &id[i]);
    }

    for (int i = 0; i < 5; i++)
        pthread_join(p[i], NULL);

    return 0;
}