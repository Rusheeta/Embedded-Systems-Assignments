//reading an array of 1000 numbers from a file

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


void main()
{
   FILE *filePtr ;
   char fileName[20];

   int flag ;
   int i ;
   int numbers[1000];//array to store numbers from a file
   int idx_num ; //index of the array
   int number ; //to scan and store each number from file
   int retVal ; //to store the return value
   
       
  
      
   printf("Enter the file name: ");
   scanf("%s", fileName);  
   

   filePtr = fopen(fileName, "r");

   if (filePtr == NULL)
   {
      printf("File open error with %s \n",fileName);
      printf("Error number returned = %d \n", errno);
      printf("%s\n",strerror(errno));
      exit(0);
   }
   
   flag = 1 ;
   idx_num = 0;

   while(flag)
   {
     retVal = fscanf(filePtr, "%d", &number);
     if (retVal == EOF)
     {
       flag = 0 ;
     }
     else
     {    
       numbers[idx_num] = number ;    
       idx_num++ ;
     }
   } 
   fclose(filePtr); 
   
   
   
   for(i = 0; i<idx_num;i++)
   {
     printf("%d ",numbers[i]);
   }      
   
   printf("Total number of elements in the array= %d\n",idx_num);
}
