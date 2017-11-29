#include<stdio.h>
#include<pthread.h>
#include<string.h>

void* palindrome(void*);
pthread_mutex_t m;
int palin;

void main(){
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_mutex_init(&m,NULL);

	pthread_create(&tid,&attr,palindrome,NULL);
	pthread_join(tid,NULL);
	
	if(palin)
		printf("String is palindrome");
	else 
		printf("String is not palindrome");
}

void* palindrome(void* str){
	char name[20];
	int len = 0,end;
	printf("Enter the string");
	scanf("%s",&name);
	len = strlen(name);
	end = len -1;
	for(int i=0;i<len;i++)
	{
		if(name[i] != name[end])
		{
			palin = 0;
			pthread_exit(0);
		}
	end--;
	}
	palin = 1;
	pthread_exit(0);
}
