#include <pthread.h>
#include <stdio.h>

typedef struct {
  int cmds;
  int executed;
  pthread_mutex_t mutex;
  pthread_cond_t full;
  pthread_cond_t empty;
} soft_mailbox_t;

pthread_t producer;
pthread_t consumer;

soft_mailbox_t soft_mailbox;

void *producer_manager(void *data) {

  while (soft_mailbox.executed) {

    pthread_mutex_lock(&soft_mailbox.mutex);

    while (soft_mailbox.cmds >= 1) {
      pthread_cond_wait(&soft_mailbox.empty, &soft_mailbox.mutex);
    }

    soft_mailbox.cmds++;
    soft_mailbox.executed--;

    printf("Producer %d %d\n", soft_mailbox.cmds, soft_mailbox.executed);

    pthread_cond_signal(&soft_mailbox.full);

    pthread_mutex_unlock(&soft_mailbox.mutex);
  }

  return NULL;
}

void *consumer_manager(void *data) {

  while (soft_mailbox.executed) {
    pthread_mutex_lock(&soft_mailbox.mutex);

    while (soft_mailbox.cmds < 1) {
      pthread_cond_wait(&soft_mailbox.full, &soft_mailbox.mutex);
    }

    soft_mailbox.cmds--;

    printf("Consumer %d %d\n", soft_mailbox.cmds, soft_mailbox.executed);

    pthread_cond_signal(&soft_mailbox.empty);

    pthread_mutex_unlock(&soft_mailbox.mutex);
  }

  return NULL;
}

int main(int argc, char const *argv[]) {

  soft_mailbox.cmds = 0;
  soft_mailbox.executed = 32;

  pthread_mutex_init(&soft_mailbox.mutex, NULL);
  pthread_cond_init(&soft_mailbox.full, NULL);
  pthread_cond_init(&soft_mailbox.empty, NULL);

  pthread_create(&producer, NULL, &producer_manager, NULL);
  pthread_create(&consumer, NULL, &consumer_manager, NULL);

  pthread_join(producer, NULL);
  pthread_join(consumer, NULL);

  return 0;
}