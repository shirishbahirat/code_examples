#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 3
#define STACK_SIZE 10

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;
volatile bool stop = false;
int stack[STACK_SIZE] = {0};
int sp = 0; // stack pointer,, also doubles as the current stack size

void SigHandler(int sig) {
  if (sig == SIGINT) {
    stop = true;
  } else {
    printf("Received unexcepted signal %d\n", sig);
  }
}

void *worker(void *param) {
  long tid = (long)(param);
  while (stop == false) {
    // acquire the lock
    pthread_mutex_lock(&m);
    while (sp <= 0) // sp should never be < 0
    {
      // there is no data in the stack to consume, wait to get signaled
      // this unlocks the mutex when it is called, and locks the
      // mutex before it returns
      pthread_cond_wait(&c, &m);
    }

    // when we get here we should be guaranteed sp >= 1
    printf("thread %ld consuming stack[%d] = %d\n", tid, sp - 1, stack[sp - 1]);
    sp--;

    pthread_mutex_unlock(&m);

    int sleepVal = rand() % 10;
    printf("thread %ld sleeping for %d seconds...\n", tid, sleepVal);
    sleep(sleepVal);
  }
  pthread_exit(NULL);
}

int main(void) {
  pthread_t threads[NUM_THREADS];
  pthread_attr_t attr;

  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  srand(time(NULL));

  for (long i = 0; i < NUM_THREADS; i++) {
    int rc = pthread_create(&threads[i], &attr, worker, (void *)i);
    if (rc != 0) {
      fprintf(stderr, "Failed to create thread %ld\n", i);
    }
  }

  while (stop == false) {
    // produce data in bursts
    int numValsToInsert = rand() % (STACK_SIZE - sp);
    printf("main producing %d values\n", numValsToInsert);
    // acquire the lock
    pthread_mutex_lock(&m);

    for (int i = 0; i < numValsToInsert; i++) {
      // produce values for the stack
      int val = rand() % 10000;
      // I think this should already be guaranteed..?
      if (sp + 1 < STACK_SIZE) {
        printf("main pushing stack[%d] = %d\n", sp, val);
        stack[sp++] = val;
        // signal the workers that data is ready
        // printf("main signaling threads...\n");
        // pthread_cond_signal(&c);
      } else {
        printf("stack full!\n");
      }
    }

    pthread_mutex_unlock(&m);

    // signal the workers that data is ready
    printf("main signaling threads...\n");
    pthread_cond_broadcast(&c);

    int sleepVal = 1; // rand() % 5;
    printf("main sleeping for %d seconds...\n", sleepVal);
    sleep(sleepVal);
  }

  for (long i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
