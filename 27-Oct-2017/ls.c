#include<stdio.h>
#include<string.h>

int main(void)
{
  char command[100];

  strcpy(command,"ls -l");

  if(system(command)<0)
     perror("Error");

  return 0;
}
