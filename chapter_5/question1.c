
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
 
       	int x = 1234;
	printf("PID is %d. Value of X is %d.\n", getpid(), x );
       	int pr = fork();
	if(pr < 0){
		fprintf(stderr,"Fork failed.\n");
		exit(1);
	}
	else if(pr == 0){
		printf("Child PID is %d. X is %d.", getpid(), x);
		x = 21;
		printf(" Changed X to 21. Check X: %d\n", x);
	}
	else{
               	int ws = wait(NULL);
		printf("Parent of %d. Parent PID: %d. X is %d.", pr, getpid(), x);
		x = 12;
		printf(" Changed X to 12. Check X: %d\n", x);
		
	}
	
	printf("PID is %d. Value of X is %d.\n", getpid(), x );
	return 0;
	
}


//Initially the value of x is 1234. After calling fork(), the child process is created.
//And It gets its own copy of X. So does the Parent process. Therefore, when the value of x is changed within
//the child process it does not affect the parent's copy of x. 
//The same thing is true when the parent process changes the value of x.


