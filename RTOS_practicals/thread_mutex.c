#include<stdio.h>
#include<pthread.h>
void* thread(void*);
pthread_mutex_t m;
void main(){
pthread_t tid;
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_mutex_init(&m,NULL);

pthread_create(&tid,&attr,thread,NULL);

pthread_join(tid,NULL);

}

void* thread(void* str){
	printf("This is a dummy function..!!");
}
