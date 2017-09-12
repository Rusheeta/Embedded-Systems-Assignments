/*4.How to generate 1000 numbers to do the search and sort it

    Write a program in C to generate 1000 random numbers and write the numbers into a file as discussed
    Copy paste that to excel Use MS excel as a col
    Sort it using Excel function and copy paste it back into your input file
*/    

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include<time.h>


void main()
{
   
   FILE *filePtr ;
   char fileName[20]; //to store filename

   int flag ;
   int i ; 
   int numbers[100]; //array to store numbers from a file
   int  idx_num ;  //index of array
   int number ;   //to scan and store each number from file   
   int  retVal ;  //to store the return value
   
      
   printf("Enter the file name: ");
   scanf("%s", fileName);  
   

   filePtr = fopen(fileName, "w");

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
   	 srand((unsigned int)time(NULL));
   	 
   	 for (i=0;i<1000;i++)
    {
	
       number=rand();
       numbers[i]=number;
       printf("number[%d]=%d/",i,numbers[i]);
       fprintf(filePtr,"%d\n",numbers[i]);
        
    }
    break;
    
   
     
     
     /*if (retVal == EOF)
     {
       flag = 0 ;
     }
     else
     {    
       numbers[idx_num] = number ;    
       idx_num++ ;
     }*/
   } 
   fclose(filePtr); 
   
   
   
       
   
   printf("Total number of elements in the array= %d\n",i);
}
