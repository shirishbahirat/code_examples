#include <pthread.h>
#include <stdio.h>

#define QSIZE 1

typedef struct {
  int cmds;
  int count;
  pthread_mutex_t mutex;
  pthread_cond_t dequeue;
  pthread_cond_t enqueue;
} cmd_queue_t;

cmd_queue_t cmd_queue;

pthread_t producer_thread;
pthread_t consumer_thread;

int prod_id;
int cons_id;

void *producer(void *data) {

  while (cmd_queue.count) {
    pthread_mutex_lock(&cmd_queue.mutex);

    while (cmd_queue.cmds >= QSIZE)
      pthread_cond_wait(&cmd_queue.dequeue, &cmd_queue.mutex);

    cmd_queue.cmds++;
    cmd_queue.count--;

    printf("enqueued cmds %d balance %d\n", cmd_queue.cmds, cmd_queue.count);

    pthread_cond_signal(&cmd_queue.enqueue);

    pthread_mutex_unlock(&cmd_queue.mutex);
  }
  return NULL;
}

void *consumer(void *data) {

  while (cmd_queue.count) {
    pthread_mutex_lock(&cmd_queue.mutex);

    while (cmd_queue.cmds < QSIZE)
      pthread_cond_wait(&cmd_queue.enqueue, &cmd_queue.mutex);

    cmd_queue.cmds--;

    printf("dequeued cmds %d balance %d\n", cmd_queue.cmds, cmd_queue.count);

    pthread_cond_signal(&cmd_queue.dequeue);

    pthread_mutex_unlock(&cmd_queue.mutex);
  }
  return NULL;
}

int main(int argc, char const *argv[]) {

  cmd_queue.cmds = 0;
  cmd_queue.count = 5;

  pthread_mutex_init(&cmd_queue.mutex, NULL);
  pthread_cond_init(&cmd_queue.dequeue, NULL);
  pthread_cond_init(&cmd_queue.enqueue, NULL);

  prod_id = pthread_create(&producer_thread, NULL, &producer, NULL);
  cons_id = pthread_create(&consumer_thread, NULL, &consumer, NULL);

  pthread_join(producer_thread, NULL);
  pthread_join(consumer_thread, NULL);

  return 0;
}