#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include <stdlib.h>
#include <errno.h>

typedef struct usage
{
	char name[10];
	int age;
	int usage;
	int planID;
	float monthlyCharges;
	struct usage *next;
}DATA;

DATA  *head= NULL ;    /*pointer to point to the start of the linked list*/
DATA  *nodePtr= NULL ; /*pointer to point to newly created node of the linked list*/
DATA  *scanPtr= NULL ; /*pointer to traverse from the start to end of the linked list*/
DATA  *dispPtr=NULL;   /*pointer to traverse and display the list*/
DATA  *maxPtr=NULL; /*pointer to traverse and find the max usage in the list*/

int max; /*to store maximum usage of all*/


 
void CreateList()
    {
    	    	
    	nodePtr=(DATA*)malloc(sizeof(DATA)); /*new node is created pointer by nodePtr*/
    	
    	if(nodePtr==NULL)
    	{
    		printf("malloc() failed: insufficient memory!\n");
    		exit(0);
		}
    	
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

void findMaxUsage()
{
	
	int temp;
	maxPtr=head;
	temp=maxPtr->usage;
	maxPtr=maxPtr->next;
	while(maxPtr!=NULL)
	{
		if(temp>=maxPtr->usage)
	    {
			max=temp;
			maxPtr=maxPtr->next;
		}
		else
		{
			temp=maxPtr->usage;
			maxPtr=maxPtr->next;
		}
	}
	max=temp;
	scanPtr=head;
	while(scanPtr!=NULL)
	{
		if(max==scanPtr->usage)
		{
			printf("Customer '%s' has the maximum usage=%d\n",scanPtr->name,max);
		}
		
		scanPtr=scanPtr->next;
	}
}

struct classified
{
	int percentArray[20];
	int bracket[20];
	int numberOfUsers[20];
	
}USER;
	
void calculatePercentage()
{
	int index;
	int i;
				
	for(index=0,i=1;index<10,i<=10;index++,i++)
	{
		USER.percentArray[index]=(max*10)*i/100;
		USER.bracket[index]=10*i;
		printf("%d ",USER.percentArray[index]);
	}
	printf("\n");		
}

void bracketOfUsers()
{
	int count;/*to count the number of users within each bracket*/
	int idx;
	int i;	
	
	for(idx=0,i=1;idx<10,i<=10;idx++,i++)
	{
		count=0;
		scanPtr=head;
		
		while(scanPtr!=NULL)
		{
			if(scanPtr->usage<=USER.percentArray[idx] && scanPtr->usage>USER.percentArray[idx-1])
			{
				count=count+1;
			}
		
			scanPtr=scanPtr->next;
		}
		USER.numberOfUsers[idx]=count;
	
		printf("No of users in the bracket of '%dpercent'= %d\n",i*10,USER.numberOfUsers[idx]);
	}

}



float PlanONE(int usage)
{
	float baseCharges;
	float totalBill;
	int temp;
	float bill;
	
	baseCharges=100;
	
	if(usage<=50)
	{
		totalBill=baseCharges;
	}
	else
	{
		temp=usage-50;
		
		if(temp<=100)
		{
			bill=temp*0.50; //50paise
		}
		else if(temp>100 && temp<=200)
		{
			bill=((temp-100)*0.55)+(100*0.50); //for first 100 50paise and next 100 55paise
		}
		else
		{
			bill=((temp-200)*0.60)+(100*0.55)+(100*0.50); //other than first 200 charges are 60paise
		}
		
		totalBill=baseCharges+bill;
	}
	
	return totalBill;
}

float PlanTWO(int usage)
{
	float baseCharges;
	float totalBill;
	int temp;
	float bill;
	
	baseCharges=300;
	
	if(usage<=75)
	{
		totalBill=baseCharges;
	}
	else
	{
		temp=usage-75;
		
		if(temp<=100)
		{
			bill=temp*0.45; //45paise
		}
		else if(temp>100 && temp<=200)
		{
			bill=((temp-100)*0.50)+(100*0.45); //for first 100 45paise and next 100 50paise
		}
		else
		{
			bill=((temp-200)*0.55)+(100*0.50)+(100*0.45); //other than first 200 charges are 55paise
		}
		
		totalBill=baseCharges+bill;
	}
	
	return totalBill;
}

float PlanTHREE(int usage)
{
	float baseCharges;
	float totalBill;
	int temp;
	float bill;
	
	baseCharges=400;
	
	if(usage<=90)
	{
		totalBill=baseCharges;
	}
	else
	{
		temp=usage-90;
		
		if(temp<=100)
		{
			bill=temp*0.45; //45paise
		}
		else if(temp>100 && temp<=200)
		{
			bill=((temp-100)*0.50)+(100*0.45); //for first 100 45paise and next 100 50paise
		}
		else
		{
			bill=((temp-200)*0.55)+(100*0.50)+(100*0.45); //other than first 200 charges are 55paise
		}
		
		totalBill=baseCharges+bill;
	}
	
	return totalBill;
}

float PlanFOUR(int usage)
{
	float baseCharges;
	float totalBill;
	int temp;
	float bill;
	
	baseCharges=500;
	
	if(usage<=100)
	{
		totalBill=baseCharges;
	}
	else
	{
		temp=usage-100;
		
		if(temp<=100)
		{
			bill=temp*0.40; //40paise
		}
		else if(temp>100 && temp<=200)
		{
			bill=((temp-100)*0.50)+(100*0.40); //for first 100 40paise and next 100 50paise
		}
		else
		{
			bill=((temp-200)*0.30)+(100*0.50)+(100*0.40); //other than first 200 charges are 30paise
		}
		
		totalBill=baseCharges+bill;
	}
	
	return totalBill;
}

void outputWriteCvs()
{
	FILE *csvWritePtr;
	char fileName[20];
	int index;
	
	/*Create a new csv file and store the above obtained result*/
   
   printf("Enter the filename to be created to store the no. of users:");
   scanf("%s",&fileName);
   
   csvWritePtr=fopen(fileName,"w");
   
   if (csvWritePtr == NULL)
   {
   		printf("File open error with %s \n",fileName);
      	printf("Error number returned = %d \n", errno);
      	printf("%s\n",strerror(errno));
      	exit(0);
   }
  
     
   fprintf(csvWritePtr,"Percentage Bracket,Number of users\n");
   
   for(index=0;index<10;index++)
   {
   		fprintf(csvWritePtr,"%d%%,%d\n",USER.bracket[index],USER.numberOfUsers[index]);
   }
   
   fclose(csvWritePtr);
   
}

void monthlyBilling()
{
	float (*arrayfxnpointer[4])(int);
   
   /*Assign address of the four functions to it*/
   
	arrayfxnpointer[0] = &PlanONE ;
	arrayfxnpointer[1] = &PlanTWO ;
	arrayfxnpointer[2] = &PlanTHREE ;
	arrayfxnpointer[3] = &PlanFOUR ;
	
	/*call the corresponding function pointer from the array*/
	
	nodePtr=head;
	
	while(nodePtr!=NULL)
	{
		nodePtr->monthlyCharges=(*arrayfxnpointer[(nodePtr->planID)-1])(nodePtr->usage);
		printf("%0.2f ",nodePtr->monthlyCharges);
		
		nodePtr=nodePtr->next;
	}	
	
	printf("\n");
}

void writeBilling() //for reference writing the final billing to a .csv file
{
	FILE *billWritePtr;
	char Filename[20];
	int index;
	
	/*Create a new csv file and store billing obtained*/
   
   	printf("Enter the filename to be created to store the billing:");
   	scanf("%s",&Filename);
   
   	billWritePtr=fopen(Filename,"w");
   
   	if (billWritePtr == NULL)
   	{
   		printf("File open error with %s \n",Filename);
      	printf("Error number returned = %d \n", errno);
      	printf("%s\n",strerror(errno));
      	exit(0);
   	}
  
     
   	fprintf(billWritePtr,"Name,age,usage,planID,total bill\n");
   
   	scanPtr=head;
   
   	while(scanPtr!=NULL)
   	{
   		fprintf(billWritePtr,"%s,%d,%d,%d,%0.2f\n",scanPtr->name,scanPtr->age,scanPtr->usage,scanPtr->planID,scanPtr->monthlyCharges);   	
   	    scanPtr=scanPtr->next;
   	}
   
   fclose(billWritePtr);
}

void main(int argc, char **argv)
{
	FILE *csvPtr;
	FILE *csvWritePtr;
	char csvFile[20];
	int flag;
	char buffer[200];
	char *record;
    char check[500];	
    int parseFlag;
    int tokenNo;
    
    
    
	if(argc>1)
	{
		strcpy(csvFile,argv[1]);
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
		
	fgets(buffer,200,csvPtr);
	printf("%s",buffer);
		

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
   
   DisplayList();   /*to display the linked list created*/
   findMaxUsage();  /*to find the customer with highest or maximum usage*/
   calculatePercentage(); /*to calculate the percentage brackets*/
   bracketOfUsers();      /*to display number of users in each bracket*/
   outputWriteCvs(); /*to store the ouput into another .csv file*/
   monthlyBilling(); /*to bill according to the planID*/
   writeBilling();   /*to store the billing amounts of respective users*/
  
}
