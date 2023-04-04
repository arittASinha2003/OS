#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
int n,f;
char buff[10];
f=open("test.txt",O_RDWR);
read(f,buff,50);
write(1,buff,50);
lseek(f,5,SEEK_SET);//skips 5 characters from the current position
read(f,buff,10);
write(1,buff,10);
}
