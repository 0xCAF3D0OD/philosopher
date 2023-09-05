#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* my_thread_func(void* param) {

	pthread_mutex_t* mutexA = (pthread_mutex_t*) param;
	int *id = (int*)param;
	
	pthread_mutex_lock(mutexA);
	printf("debut du mutex\n");
	
	printf("Printing id: %d\n", *id);
	
	printf("fin du mutex\n");
	pthread_mutex_unlock(mutexA);
	free(id);
	pthread_exit(NULL);
}

int main(void) {
	pthread_t t_id[5];
	pthread_mutex_t mutex;
	
	pthread_mutex_init(&mutex, NULL);
	printf("before thread\n");
	for (int i = 0; i < 4; i++) {
		int* threadId = (int*)malloc(sizeof(int));
		*threadId = i + 1;
		pthread_create(&t_id[i], NULL, my_thread_func, (void*) threadId);
	}
	for (int j = 0; j < 4; j++)
		pthread_join(t_id[j], NULL);
	pthread_mutex_destroy(&mutex);	
	return (0);
}
