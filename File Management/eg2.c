#include<stdio.h>
#include<unistd.h>
int main()
{
int count;

count=write(1,"hello\n",3);
printf("Total bytes written: %d\n",count);
}
