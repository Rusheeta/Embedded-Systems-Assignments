#include<stdio.h>
#include<string.h>


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
	char String[100];   //Array to enter a string
	int String_length;  //To store length of the string
	int Length_builtin; //To store length of the string using strlen()	

	
	printf("Enter the string: \n");
	scanf("%[^\n]s",&String);
		
	printf("String:%s\n",String);
	
	String_length=stringLength(String);	
	printf("Length of the string: %d\n",String_length);
	
	Length_builtin=strlen(String);
	printf("Length of the string using built in function: %d\n",String_length);
	
}
