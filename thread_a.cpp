#include <stdio.h>
#include <pthread.h>


void* thread_function(void* arg)
{

	printf("thread number %d\n", 1);
	return NULL;
}

int main(int argc, const char* argv[])
{
	pthread_t thread_id;
	void* exit_status;

	pthread_create(&thread_id, NULL, thread_function, NULL);

	pthread_join(thread_id, &exit_status);

	return 0;
}