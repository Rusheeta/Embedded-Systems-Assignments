#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signum)
{
  if(signum==SIGSEGV)
    printf("\nHandler output:Received SIGSEGV\n");

  printf("\nWhen default SIGSEGV signal is called inside the handler:\n");
  signal(signum,SIG_DFL);
  kill(getpid(),signum); //to send default sigsegv signal to the process and generate core dump file
}

int main(void)
{
  if(signal(SIGSEGV,sig_handler)==SIG_ERR)
    printf("\nCan't catch SIGSEGV\n");

  //A long long wait so that we can easily issue a signal to this process

  printf("Process %d is running......\n",getpid());
  while(1)
  {
  }
  sleep(1);
  return 0;
}
