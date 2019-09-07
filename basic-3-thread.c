#include <pthread.h>
#include <stdio.h>

pthread_t thread;
int thread_id;

void *thread_entry_function(void *data) {
  int id = *((int *)data);

  printf("In thread entry - %d\n", id);

  return NULL;
}

int main(int argc, char const *argv[]) {

  int data = 123;
  thread_id =
      pthread_create(&thread, NULL, &thread_entry_function, (void *)&data);

  pthread_join(thread, NULL);
  return 0;
}