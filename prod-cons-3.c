#include <pthread.h>
#include <stdio.h>

pthread_t producer;
pthread_t consumer;

typedef struct {
  int cmds;
  int executed;
  pthread_mutex_t mutex;
  pthread_cond_t full;
  pthread_cond_t empty;
} cmd_mbox_t;

cmd_mbox_t cmd_mbox;

void *producer_thread(void *data) {

  while (cmd_mbox.executed) {

    pthread_mutex_lock(&cmd_mbox.mutex);

    while (cmd_mbox.cmds >= 1) {
      pthread_cond_wait(&cmd_mbox.empty, &cmd_mbox.mutex);
    }

    cmd_mbox.cmds++;

    cmd_mbox.executed--;

    printf("Producer enq %d exe %d\n", cmd_mbox.cmds, cmd_mbox.executed);

    pthread_cond_signal(&cmd_mbox.full);

    pthread_mutex_unlock(&cmd_mbox.mutex);
  }

  return NULL;
}

void *consumer_thread(void *data) {

  while (cmd_mbox.executed) {

    pthread_mutex_lock(&cmd_mbox.mutex);

    while (cmd_mbox.cmds < 1) {
      pthread_cond_wait(&cmd_mbox.full, &cmd_mbox.mutex);
    }

    cmd_mbox.cmds--;

    printf("Consumer deq %d exe %d\n", cmd_mbox.cmds, cmd_mbox.executed);

    pthread_cond_signal(&cmd_mbox.empty);

    pthread_mutex_unlock(&cmd_mbox.mutex);
  }

  return NULL;
}

int main(int argc, char const *argv[]) {

  cmd_mbox.cmds = 0;
  cmd_mbox.executed = 5;

  pthread_mutex_init(&cmd_mbox.mutex, NULL);
  pthread_cond_init(&cmd_mbox.full, NULL);
  pthread_cond_init(&cmd_mbox.empty, NULL);

  pthread_create(&producer, NULL, &producer_thread, NULL);
  pthread_create(&consumer, NULL, &consumer_thread, NULL);

  pthread_join(producer, NULL);
  pthread_join(consumer, NULL);

  return 0;
}