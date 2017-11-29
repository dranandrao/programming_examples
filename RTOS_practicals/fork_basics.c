#include<stdio.h>
void main(){
	printf("Calling fork system call\n");
	int result = fork();
	if(result == 0)
	{
		if (fork() == 0)
		{
			printf("Child block 2..!!\n");
			printf("Child block 2... process id --> %d\n",getpid());
			printf("Parent process id of child 2--> %d\n",getppid());
		} else {
			wait();
			printf("child block 1..!!\n");	
			printf("Child block 1... process id --> %d\n",getpid());	
			printf("Parent process id of child 1--> %d\n",getppid());		
		}
	} else {
		wait();
		printf("Parent block..!!\n");
	}
}
