#include<pthread.h>
#include<stdio.h>
int sum;
void *runner(void *param);
void *demo();
int main(int argc,char *argv[])
{
pthread_t tid;//thread identifier.
pthread_attr_t attr;//set of thread attributes.

if(argc != 2){
	fprintf(stderr,"usage: a.out<integer value>\n");
	return -1;
}
if(atoi(argv[1]) < 0){
	fprintf(stderr,"%d must be >= 0 \n",atoi(argv[1]));
	return -1;
}

pthread_attr_init(&attr);
pthread_create(&tid,&attr,runner,argv[1]);
pthread_create(&tid,&attr,demo,NULL);
pthread_join(tid,NULL);

printf("sum = %d \n",sum);

}

void *runner(void *param){
	int i,upper = atoi(param);
	sum =0;

	for(i=1;i<=upper;i++)
		sum += i;

	pthread_exit(0);
}

void *demo(){
	printf("this is a demo function...");
}
