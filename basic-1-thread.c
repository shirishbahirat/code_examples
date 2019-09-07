#include <pthread.h>
#include <stdio.h>

int thr_id;
pthread_t p_thread;

void *do_loop(void *data) {

  int i, j, me = *((int *)data);

  for (i = 0; i < 10; ++i) {
    for (j = 0; j < 500000000; ++j) {
    }
    printf("%d - Got %d\n", me, i);
  }

  return NULL;
}

int main(int argc, char const *argv[]) {
  int a = 1, b = 2, c = 3, d = 4;
  thr_id = pthread_create(&p_thread, NULL, do_loop, (void *)&a);

  thr_id = pthread_create(&p_thread, NULL, do_loop, (void *)&b);

  thr_id = pthread_create(&p_thread, NULL, do_loop, (void *)&c);

  do_loop((void *)&d);

  pthread_join(p_thread, NULL);

  return 0;
}