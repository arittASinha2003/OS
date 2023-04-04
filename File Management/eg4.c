#include<unistd.h>
int main()
{
char buff[200];
read(0,buff,100);//read 10 bytes from standard input device(keyboard), store in buffer (buff)
write(1,buff,100);//print 10 bytes from the buffer on the screen
}
