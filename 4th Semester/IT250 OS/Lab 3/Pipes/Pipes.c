// C program to illustrate 
// pipe system call in C 
// shared by Parent and Child 
#include <stdio.h> 
#include <unistd.h> 
#define MSGSIZE 16 
char* msg1 = "hello, world #1"; 
char* msg2 = "hello, world #2"; 
char* msg3 = "hello, world #3";
char* parent = "from parent";
char* child = "from child";

int main() 
{ 
	char inbuf[MSGSIZE]; 
	int p[2], pid, nbytes; 

	if (pipe(p) < 0) 
		exit(1); 

	/* continued */
	if ((pid = fork()) > 0) { 
		printf("Parent Process\n");
		write(p[1], msg1, MSGSIZE); 
		write(p[1], msg2, MSGSIZE);
		write(p[1], msg3, MSGSIZE);
		printf("Parent Process done\n");
		// Adding this line will 
		// not hang the program 
		close(p[1]); 
		// wait(NULL); 
	} 

	else { 
		printf("Child Process\n");
		// Adding this line will 
		// not hang the program 
		close(p[1]); 
		while ((nbytes = read(p[0], inbuf, MSGSIZE)) > 0) 
			printf("% s\n", inbuf); 
		if (nbytes != 0) 
			exit(2); 
		printf("Finished reading in Child Process\n");
		 
	} 
	return 0; 
} 
