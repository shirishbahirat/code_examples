#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;

void* thread_function(void* arg)
{
	int* number = (int*)arg;

	pthread_mutex_lock(&lock);
	printf("%s %d\n", "my_thread", *number);
	pthread_mutex_unlock(&lock);
	return NULL;
}


int main(int argc, const char* argv[])
{
	pthread_t id;
	void* status;
	int i = 0;

	pthread_mutex_init(&lock, NULL);

	for (int j=0; j<10; ++j)
	{
		pthread_create(&id, NULL, thread_function, (void*)&j);
		sleep(1);
	}

	pthread_join(id, &status);

	pthread_mutex_destroy(&lock);

	return 0;
}
