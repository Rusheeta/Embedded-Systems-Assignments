#include<stdio.h>
#include<string.h>

char *stringCopy(char stringArray[200]) //function to copy a string from one array to another
{
	static char tempArray[100];//to store the copied string
	int idx;                   //index to store each character
	
	idx=0;
	
	while(stringArray[idx]!='\0')
	{
	tempArray[idx]=stringArray[idx];
	idx++;	
	}
	
    return tempArray;
}

int stringLength(char stringArray[200]) //function to calculate length of the string
{
	int length; //to store length of the string
	int idx;    //to store index of the stringArray
	
	idx=0;
	while(stringArray[idx]!='\0')
	{
	length=idx+1;
	idx++;	
	}
	return length;
}

main()
{
	char firstString[100]={" "};   //Array to enter a string
	char secondString[100]= {" "};  //Array to store copy of the previous string
	char *ptr;  //to store the address of the array returned from the function
	int index;  //to store the content of the pointer  
	int length; //length of first string                   
	
	printf("Enter a string: \n");
	scanf("%[^\n]s",&firstString);
	
	ptr=stringCopy(firstString);
	length=stringLength(firstString);
	
	for(index=0;index<length;index++)
	{
		secondString[index]=*(ptr+index);
	}
	
	printf("secondString(without using strcpy()): %s\n",secondString);
	
	strcpy(secondString,firstString);	
	printf("secondString(using strcpy()): %s\n",secondString);
}
