#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc, char *argv[])
{ 
printf(" we are ex2.c\n");
printf("PID Of ex2.c =%d\n", getpid());
return 0;
}
