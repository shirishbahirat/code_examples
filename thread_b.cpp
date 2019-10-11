#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg)
{
	printf("%s\n", "thread_function");

	return NULL;
}



int main(int argc, const char* argv[])
{
	pthread_t id;
	void* status;

	pthread_create(&id, NULL, thread_function, NULL);

	pthread_join(id, &status);


	return 0;
}