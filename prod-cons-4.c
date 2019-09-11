#include <pthread.h>
#include <stdio.h>

pthread_t producer;
pthread_t consumer;

typedef struct {
  int cmds;
  int executed;
  pthread_cond_t full;
  pthread_cond_t empty;
  pthread_mutex_t mutex;
} cmd_context_t;

cmd_context_t cmd_context;

void *producer_thread(void *data) {

  while (cmd_context.executed) {
    pthread_mutex_lock(&cmd_context.mutex);

    while (cmd_context.cmds >= 1) {
      pthread_cond_wait(&cmd_context.empty, &cmd_context.mutex);
    }

    cmd_context.cmds++;
    cmd_context.executed--;

    printf("Producer %d %d\n", cmd_context.cmds, cmd_context.executed);

    pthread_cond_signal(&cmd_context.full);

    pthread_mutex_unlock(&cmd_context.mutex);
  }

  return NULL;
}

void *consumer_thread(void *data) {

  while (cmd_context.executed) {
    pthread_mutex_lock(&cmd_context.mutex);

    while (cmd_context.cmds < 1) {
      pthread_cond_wait(&cmd_context.full, &cmd_context.mutex);
    }

    cmd_context.cmds--;

    printf("Consumer %d %d\n", cmd_context.cmds, cmd_context.executed);

    pthread_cond_signal(&cmd_context.empty);

    pthread_mutex_unlock(&cmd_context.mutex);
  }

  return NULL;
}

int main(int argc, char const *argv[]) {

  cmd_context.cmds = 0;
  cmd_context.executed = 32;

  pthread_mutex_init(&cmd_context.mutex, NULL);
  pthread_cond_init(&cmd_context.full, NULL);
  pthread_cond_init(&cmd_context.empty, NULL);

  pthread_create(&producer, NULL, &producer_thread, NULL);
  pthread_create(&consumer, NULL, &consumer_thread, NULL);

  pthread_join(producer, NULL);
  pthread_join(consumer, NULL);

  return 0;
}