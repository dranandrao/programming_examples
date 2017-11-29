#include<stdio.h>
#include<pthread.h>
void* thread1(int*);

pthread_mutex_t m;
void main(){
printf("main begins..!!");
pthread_t tid[10];
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_mutex_init(&m,NULL);

for (int i=0;i<10;i++)
{
	pthread_create(&tid[i],&attr,&thread1,&i);
	pthread_join(tid[i],NULL);
	
}
printf("main ends..!!");
}

void* thread1(int* value){
pthread_mutex_lock(&m);
FILE *file;
char filename[10];
printf("Enter the file name");
scanf("%s",&filename);
file = fopen(filename,"w");
fprintf(file,"This file is created by %d thread",&value);
fclose(file);
pthread_mutex_unlock(&m);
pthread_exit(0);
}
