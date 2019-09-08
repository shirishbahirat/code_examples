#include <pthread.h>
#include <stdio.h>

#define CMDS 32
#define QD 1

pthread_t producer;
pthread_t consumer;

typedef struct {
  int cmds;
  int executed;
  pthread_mutex_t mutex;
  pthread_cond_t pending;
  pthread_cond_t empty;
} cmd_mailbox_t;

cmd_mailbox_t cmd_mailbox;

void *producer_entry_function(void *data) {

  while (cmd_mailbox.executed < CMDS) {

    pthread_mutex_lock(&cmd_mailbox.mutex);

    while (cmd_mailbox.cmds >= QD) {
      pthread_cond_wait(&cmd_mailbox.empty, &cmd_mailbox.mutex);
    }

    cmd_mailbox.cmds++;
    cmd_mailbox.executed++;

    printf("Producer added cmds %d balance %d\n", cmd_mailbox.cmds,
           cmd_mailbox.executed);

    pthread_cond_signal(&cmd_mailbox.pending);

    pthread_mutex_unlock(&cmd_mailbox.mutex);
  }

  return NULL;
}

void *consumer_entry_function(void *data) {

  while (cmd_mailbox.executed < CMDS) {

    pthread_mutex_lock(&cmd_mailbox.mutex);

    while (cmd_mailbox.cmds < QD) {
      pthread_cond_wait(&cmd_mailbox.pending, &cmd_mailbox.mutex);
    }

    cmd_mailbox.cmds--;

    printf("Consumer serviced cmds %d balance %d\n", cmd_mailbox.cmds,
           cmd_mailbox.executed);

    pthread_cond_signal(&cmd_mailbox.empty);

    pthread_mutex_unlock(&cmd_mailbox.mutex);
  }

  return NULL;
}

int main(int argc, char const *argv[]) {

  cmd_mailbox.cmds = 0;
  cmd_mailbox.executed = 0;

  pthread_mutex_init(&cmd_mailbox.mutex, NULL);
  pthread_cond_init(&cmd_mailbox.pending, NULL);
  pthread_cond_init(&cmd_mailbox.empty, NULL);

  pthread_create(&producer, NULL, &producer_entry_function, NULL);
  pthread_create(&consumer, NULL, &consumer_entry_function, NULL);

  pthread_join(producer, NULL);
  pthread_join(consumer, NULL);

  return 0;
}