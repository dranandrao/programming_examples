#include<stdio.h>
#include<pthread.h>

void* thread1(void*);
void* thread2(void*);

int flag[2];
int turn;

void main(){
	pthread_t tid1,tid2;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_create(&tid1,&attr,thread1,NULL);
	pthread_create(&tid2,&attr,thread2,NULL);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
}

void* thread1(void* str){
	flag[0] = 1;
	turn = 1;
	while(flag[1] && turn == 1);
	for (int i=0;i<10;i++)
		printf("%d\n",i);
	flag[0] = 0;
	pthread_exit(0);
}

void* thread2(void* str){
	flag[1] = 1;
	turn = 0;
	while(flag[0] && turn == 0);
	for (int i=101;i<110;i++)
		printf("%d\n",i);
	flag[1] = 0;
	pthread_exit(0);
}
