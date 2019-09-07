#include "pthread.h"
#include "stdio.h"

pthread_t t_pthread;
int thread_id;

void *thread_function(void *data) {

  int input = *((int *)data);

  printf("In thread function - %d\n", input);

  return NULL;
}

int main(int argc, char const *argv[]) {

  int data = 10;

  int thread_id =
      pthread_create(&t_pthread, NULL, &thread_function, (void *)(&data));

  pthread_join(t_pthread, NULL);

  return 0;
}