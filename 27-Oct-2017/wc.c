#include<stdio.h>
#include<string.h>

int main(void)
{
  char command[50];
  char filename[20];

  strcpy(command,"wc ");
  printf("Enter filename to find the word count:\n");
  scanf("%s",filename);

  strncat(command,filename,20);

  if(system(command)<0)
     perror("Error");

  return 0;
}
