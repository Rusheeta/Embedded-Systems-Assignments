#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>
#include <sys/stat.h>

int main(void)
{
  pid_t childPID;
  FILE *childPtr;
  FILE *parentPtr;

  childPID=fork();

  if(childPID>=0) //fork was successful
  {
    if(childPID==0) //child process
    {
      printf("Child process executing %d\n",childPID);
      printf("Child process ID: %d\n",getpid());

      childPtr=fopen("killchildprocess","w");
      if(childPtr==NULL)
      {
        printf("Error:%s\n",strerror(errno));
        exit(0);
      }
      else
      {
        fprintf(childPtr,"#! /bin/sh\n");
        fprintf(childPtr,"kill -9 %d\n",getpid());
      }
      fclose(childPtr);

      chmod("killchildprocess",S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH); //to grant permission to child process

      while(1)
      {
      }
    }
    else   //Parent process
    {
      printf("Parent process executing %d\n",childPID);
      printf("Parent process ID: %d\n",getpid());

      parentPtr=fopen("killparentprocess","w");
      if(parentPtr==NULL)
      {
        printf("Error:%s\n",strerror(errno));
        exit(0);
      }
      else
      {
        fprintf(parentPtr,"#! /bin/sh\n");
        fprintf(parentPtr,"kill -9 %d\n",getpid());
      }
      fclose(parentPtr);

      chmod("killparentprocess",S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH); //to grant permission to parent process

      while(1)
      {
      }
    }
  }
  else   //fork failed
  {
    printf("\n Fork failed, quitting!!!!\n");
    return 1;
  }

  return 0;
}
