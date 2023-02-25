//gcc race_condition.cpp -o race_condition -lstdc++
// -pthread //if doesn't work
#include <stdio.h>
#include <pthread.h>
int i_global=0;
pthread_mutex_t mutex_var;
void increment(){
	pthread_mutex_lock(&mutex_var);
	for(int i=0;i<10000000;i++){
		i_global++;
	}
	pthread_mutex_unlock(&mutex_var);
}
int main(){
	printf("akhil");
	pthread_t t1,t2;
	pthread_mutex_init(&mutex_var, NULL);
	pthread_create(&t1, NULL, &increment, NULL);
	pthread_create(&t2, NULL, &increment, NULL);
	pthread_join(t1, NULL); //wait untill it finishes execution
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&mutex_var);
//	increment();
//	increment();
	printf("i_global %d",i_global);
	return 0;
}
