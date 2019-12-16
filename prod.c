#include <pthread.h>
#include <stdio.h>

pthread_t producer_thread;
pthread_t consumer_thread;

pthread_cond_t cond;
pthread_mutex_t lock;

int count;

void *consumer_thread_function(void *arg) {

  while (1) {

    printf("Consumer before lock %d\n", count);
    pthread_mutex_lock(&lock);
    printf("Consumer after lock %d\n", count);

    count++;
    printf("Consumer count increment %d\n", count);

    pthread_cond_signal(&cond);
    printf("Consumer after cond %d\n", count);

    pthread_mutex_unlock(&lock);
    printf("Consumer after unlock %d\n", count);

    if (count > 3)
      break;
  }

  return NULL;
}

void *producer_thread_function(void *arg) {

  while (1) {
    printf("Producer before lock %d\n", count);
    pthread_mutex_lock(&lock);
    printf("Producer before wait %d\n", count);
    while (count < 2)
      pthread_cond_wait(&cond, &lock);
    printf("Producer after wait %d\n", count);

    count--;
    printf("Producer after increment %d\n", count);

    // pthread_cond_broadcast(&cond);
    // printf("Producer after broadcast %d\n", count);

    pthread_mutex_unlock(&lock);
    printf("Producer thread after unlock %d\n", count);
    if (count > 3)
      break;
  }

  return NULL;
}

int main(int argc, char const *argv[]) {

  count = 0;

  pthread_create(&producer_thread, NULL, producer_thread_function, NULL);
  pthread_create(&consumer_thread, NULL, consumer_thread_function, NULL);

  pthread_join(producer_thread, NULL);
  pthread_join(consumer_thread, NULL);

  printf("Model thread init\n");

  return 0;
}