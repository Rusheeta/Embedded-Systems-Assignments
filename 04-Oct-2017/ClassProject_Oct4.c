#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct usage
{
	char name[10];
	int age;
	int usage;
	int planID;
	struct usage *next;
}DATA;

DATA  *head= NULL ;    /*pointer to point to the start of the linked list*/
DATA  *nodePtr= NULL ; /*pointer to point to newly created node of the linked list*/
DATA  *scanPtr= NULL ; /*pointer to traverse from the start to end of the linked list*/
DATA  *dispPtr=NULL;   /*pointer to traverse and display the list*/
 
void CreateList()
    {
    	    	
    	nodePtr=(DATA*)malloc(sizeof(DATA)); /*new node is created pointer by nodePtr*/
    	
        if(head==NULL)
        {
    	    head=nodePtr;  /*Mark the beginning of the node*/
    	    scanPtr=nodePtr; 
    	    nodePtr->next=NULL;
	   	}
        else
        {
        	scanPtr->next=nodePtr; /*Link the previous node's next pointer to the newly created node*/
    		scanPtr=nodePtr; /*Make scanPtr point to the newly created node*/
    		nodePtr->next=NULL; /*setting next pointer to NULL after creating a new node in case this is the last node in the list*/
		}
		
	/*	nodePtr->name=info;	 
		nodePtr->age=
		nodePtr->planID=
		nodePtr->usage */  				    	
	}
	
void DisplayList()
{
	dispPtr=head;		
			
	if(dispPtr!=NULL)
	{
		
		while(dispPtr!=NULL)
		{
			printf("%s ",dispPtr->name);
			printf("%d ",dispPtr->age);
			printf("%d ",dispPtr->usage);
			printf("%d ",dispPtr->planID);
			printf("\n");
			dispPtr=dispPtr->next;
		}
	}	
	else
	{
		printf("List is Empty\n");
	}
}

void main(int argc, char **argv)
{
	FILE *csvPtr;
	char csvFile[20];
	int flag;
	int index;
	char buffer[200];
	char *record;
    char check[500];	
    int parseFlag;
    int tokenNo;
    
	if(argc>1)
	{
		strcpy(csvFile,argv[1]);
		printf("argc=%d\n",argc);
	}
	
	
	else
	{
		printf("Wrong command line arguments.\n");
		exit(1);
	}
	
	csvPtr=fopen(csvFile,"r");
	
	if(csvPtr==NULL)
	{
		printf("Unable to open the csv file.\n");
		exit(1);
	}
	
	flag=1;
	index=0;
	
	fgets(buffer,200,csvPtr);
	
		

    while(flag)
	{
		if(fgets(buffer,200,csvPtr)==NULL)
		{
			flag=0;
			continue;
		}
		
		parseFlag = 1;
        tokenNo=0;
        
        record = strtok(buffer,","); 
        CreateList();
        strcpy(nodePtr->name,record);
         
        
        tokenNo++;

        while(parseFlag)
        {
            record = strtok(NULL,","); 
           // printf(" %d  token = %s \n ",tokenNo, record);
            
         
            if (record == NULL)
            {
                parseFlag = 0 ;
                continue ;
            } 	
            switch(tokenNo)
            {
                case 1 : 
				    {
				    	
						nodePtr->age=atoi(record);						                        
                        break ;
                    }
           
                case 2 : 
                    { 
                        nodePtr->usage=atoi(record);
                        break ;
                    }
                case 3 : 
                    { 
                        nodePtr->planID =atoi(record);
                        break ;
                    }
                default:
                	{
                		break;
					}
            }
            tokenNo++;
	    }
   }
   fclose(csvPtr);
   DisplayList();
}
