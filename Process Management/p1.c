#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{ 
fork ();
printf("hello welcome\nPID= %d\n", getpid());
return 0;
}
