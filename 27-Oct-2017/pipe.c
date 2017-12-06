#include<stdio.h>
#include<unistd.h>

int main(void)
{
  int fd[2];

  pipe(fd);

  if(fork()==0)
  {
    close(1);
    dup(fd[1]);
    close(fd[0]);
    execlp("ls","ls","-l",NULL); //ouput of ls -l to input of pipe
  }
  else
  {
    close(0);
    dup(fd[0]);
    close(fd[1]);
    execlp("wc","wc",NULL);  //output of pipe to input of wc
  }
  return 0;
}
