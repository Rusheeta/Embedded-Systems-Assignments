#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include<time.h>

int LinearSearch(FILE *ptr,int SearchArray[100],int SearchNum,int length)//function for linear search
{
	int found=0;        // to show number is found or not
	int idx;
	int comparisons=0; //to get number of comparisons
	//clock_t t;
	
	//t=clock();
		
	for(idx=0;idx<length;idx++)
	{
		if(SearchArray[idx]==SearchNum)
		{
			found=1;
			comparisons++;
		    break;		    
		}
		 
	comparisons++;
		
	}
	

	printf("Total number of elements in the array= %d\n",length);    
	printf("No. of comparisons= %d\n",comparisons);
	
	fprintf(ptr,"Total number of elements in the array= %d\n<br>",length);    
	fprintf(ptr,"No. of comparisons= %d\n<br>",comparisons);
	return found;
	
}

int main()
{
   FILE *filePtr ;
   FILE *LinearhtmlPtr;
   char fileName[10]; //to store filename
   char htmlFile[10];

   int flag ;
   int i ; 
   int numbers[100]; //array to store numbers from a file
   int  idx_num ;  //index of array
   int number ;   //to scan and store each number from file
   int search_number; //to store the number to be searched
   int  retVal ;  //to store the return value
   int present;  // to show number is found or not
   
   printf("Enter the html file name: ");
   scanf("%s", htmlFile);  
   

   LinearhtmlPtr = fopen(htmlFile, "w");

   if (LinearhtmlPtr == NULL)
   {
      printf("File open error with %s \n",htmlFile);
      printf("Error number returned = %d \n", errno);
      printf("%s\n",strerror(errno));
      exit(0);
   }
   
   flag = 1 ;
   idx_num = 0;

   while(flag)
   {
   
   fprintf(LinearhtmlPtr,"<html>\n");	
   fprintf(LinearhtmlPtr,"<h1>LINEAR SEARCH</h1>");
   
   printf("Enter the file name: ");
   scanf("%s", fileName);  
   
   fprintf(LinearhtmlPtr,"<p><b>Enter the file name:</b> %s<br>",fileName);

   filePtr = fopen(fileName, "r");

   if (filePtr == NULL)
   {
      fprintf(LinearhtmlPtr,"File open error with <b>%s</b> <br>",fileName);
      fprintf(LinearhtmlPtr,"Error number returned = <b>%d</b> <br>", errno);
      fprintf(LinearhtmlPtr,"<b>%s</b><br>",strerror(errno));
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
     printf("%d ", numbers[i]);
     fprintf(LinearhtmlPtr,"<b>%d</b> ",numbers[i]);
   }
   
   fprintf(LinearhtmlPtr,"<br>");
         
   printf("\nEnter number to be searched: \n");
   scanf("%d",&search_number);   
   
   fprintf(LinearhtmlPtr,"\n<b>Enter number to be searched:</b> %d\n<br>",search_number); 
   
   present=LinearSearch(LinearhtmlPtr,numbers,search_number,idx_num);   

     if(present==1)
	{
		printf("The number %d is PRESENT in the array.\n",search_number);
		fprintf(LinearhtmlPtr,"The number %d is PRESENT in the array.\n<br>",search_number);		
	}
	else
	{
		printf("The number %d is NOT PRESENT in the array.\n",search_number);
		fprintf(LinearhtmlPtr,"The number %d is NOT PRESENT in the array.\n<br>",search_number);		
	}
    
     
   }    
   
   fclose(LinearhtmlPtr); 
}
      
   

