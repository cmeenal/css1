#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	//reserve buffer space of 5 bytes + the terminating NULL
	//if allocated space exceeds 8 bytes, there is overflow
	char buffer[5];
	
	//no overflow
	if(argc<2)
	{
		printf("strcpy() NOT executed\nSYNTAX: %s <characters>\n",argv[0]);
		exit(0);
	}//if
	
	//overflow has occured
	strcpy(buffer,argv[1]);
	printf("The buffer content=%s\nstrcpy() executed\n",buffer);
	return 0;
}//main

/*OUTPUT
user@user:~$ gcc css10.c
user@user:~$ ./a.out
strcpy() NOT executed
SYNTAX: ./a.out <characters>
user@user:~$ ./a.out 1 2
The buffer content=1
strcpy() executed
user@user:~$ ./a.out 1 
The buffer content=1
strcpy() executed
user@user:~$ ./a.out meenal
The buffer content=meenal
strcpy() executed
user@user:~$ ./a.out hacked!
The buffer content=hacked!
user@user:~$ ./a.out New York City USA
The buffer content=New
strcpy() executed
user@user:~$ ./a.out 1,22 32
The buffer content=1,22
strcpy() executed
*/
