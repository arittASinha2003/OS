#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc, char *argv[])
{ 
printf("PID of ex1.c = %d\n",getpid());
char *args[] = {"hello","world", NULL};
execv("./ex2",args);
printf("back to exc1.c");
return 0;
}
