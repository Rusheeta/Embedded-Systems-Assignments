#include<stdio.h>
#include<string.h>



char *stringToken(char* buffer, const char *delimiter)
{
    static char *ptr;     //to return the tokens
	static char *ibuffer; //to compare the elements of the string with delimiter
    const   char *del;    //to point delimiter
    
	if(buffer!=NULL)
	{
		ibuffer=buffer;
		ptr=buffer;
	}
	else
	{
		if(*ibuffer=='\0')
		return NULL;		
		ptr=ibuffer;
	}
	
	
	while(*ibuffer!='\0')
	{
		
		del=delimiter;
		
		while(*del!='\0')
		{
			if(*ibuffer==*del)
	     	{			 
				if(ibuffer==ptr)
			    {
				    ibuffer++;ptr++;
				}
			    else
				{
				    *ibuffer='\0';		
				    ibuffer++;				    
				    return ptr;
		        }
		    }
	     	else
		    {
				del++;
			}
	    }
		ibuffer++;
	}
	
	return ptr;	 
}




main()
{
	char string[90]="Hello,my,name,is,stella";
	char string1[90]="Hello,my,name,is,stella";
	char *token;      //to store and print the token returned from the function
	char *token_strtok; //to store and print the token using strtok()	
	char del[10]=","; //delimiter character	
	int tokenNo;      //to number each token	
	
	
	printf("string=%s\n",string);
	
	tokenNo=1;		
	token=stringToken(string,del);   
	token_strtok=strtok(string1,del); 	
		 
    while( (token != NULL)&&(token_strtok != NULL) ) 
    {
        printf( "%d token= %s\n",tokenNo, token );
    
        token = stringToken(NULL,del);
        
        printf( "%d token_using_strtok= %s\n",tokenNo, token_strtok );
    
        token_strtok = strtok(NULL,del);
        tokenNo++;
    }
    
	
}
