#include<stdio.h>
#include<malloc.h>

typedef struct node 
    {
       int data ;
       struct node *next ;
    } NODE ;
    
    /* Declare pointers of the list as a Global Variable */
    
    NODE  *head= NULL ;    /*pointer to point to the start of the linked list*/
    NODE  *scanPtr= NULL ; /*pointer to traverse from the start to end of the linked list*/
    NODE  *nodePtr= NULL ; /*pointer to point to newly created node of the linked list*/
    NODE  *dispPtr=NULL;   /*pointer to traverse and display the list*/
    NODE  *searchPtr=NULL; /*pointer to traverse and search for data in the list*/
    NODE  *newNodePtr= NULL ;/*pointer to point to the new node created to insert into the list*/
    
	int DisplayMenu()
    {
    	int option;
    	
    	printf("\nMenu:\n");
    	printf("1.Create List\n");
    	printf("2.Insert Node\n");
    	printf("3.Delete Node\n");
    	printf("4.Display List\n");
    	printf("5.Delete List\n");
    	printf("6.Search List\n");
    	printf("7.Exit\n");
    	
    	printf("Choose an option to perform the action:\n");
    	scanf("%d",&option);
    	
		return option;    	
	}
	
    void CreateList()
    {
    	int info;    
    	
		printf("Enter data to be stored in a list: \n");
    	scanf("%d",&info);
    	
    	nodePtr=(NODE*)malloc(sizeof(NODE)); /*new node is created pointer by nodePtr*/
    	
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
		
		nodePtr->data=info;	    				    	
	}
	
	void InsertNode()
	{
		int newData;    
		int info;
		
		if(head!=NULL)
		{
			printf("Enter data to be stored in the new node: \n");
    		scanf("%d",&newData);
    	
    		newNodePtr=(NODE*)malloc(sizeof(NODE)); /*new node is created by newNodePtr*/
    		newNodePtr->data=newData;
    		newNodePtr->next=NULL;
    	
    		printf("Enter data after which new node is to be inserted: ");
    		scanf("%d",&info);
    	
    		scanPtr=head;
    	
    		while(scanPtr!=NULL)
        	{	
    	    	if(scanPtr->data==info)
				{
					newNodePtr->next=scanPtr->next;
					scanPtr->next=newNodePtr;
    				break;
				}	
				scanPtr=scanPtr->next;
	    	}    		
		}
		else
		{
			printf("Insertion is not possible: List is empty\n");
		}    		
	}
	
	void DeleteNode()
	{
		int delInfo;
						   	
     	if(head!=NULL)
		{
			printf("Enter data whose node is to be deleted : ");
    	  	scanf("%d",&delInfo);
    	
    		scanPtr=head;
    		searchPtr=scanPtr->next;
    	
    	
    		if(head->data==delInfo)
    		{
    			head=scanPtr->next;
    			free(scanPtr);
    			scanPtr=NULL;
	   		}
			else
			{
				while(searchPtr!=NULL)
    	    	{
    				if(searchPtr->data==delInfo)
    				{
    					scanPtr->next=searchPtr->next;
    					free(searchPtr);
    					searchPtr=NULL;
    					break;
					}
					searchPtr=searchPtr->next;
					scanPtr=scanPtr->next;
				}			
			}    	
		}
		else
		{
			printf("Deletion is not possible: List is empty\n");
		}    	
	}
	
	void DisplayList()
	{
		dispPtr=head;		
			
		if(dispPtr!=NULL)
		{
			printf("List: ");
			while(dispPtr!=NULL)
			{
				printf("%d ",dispPtr->data);
				dispPtr=dispPtr->next;
			}
		}	
		else
		{
			printf("List is Empty\n");
		}
	}
	
	void DeleteList()
	{
		if(head!=NULL)
		{
			scanPtr=head;
			while(scanPtr!=NULL)
			{
				head=scanPtr->next;
				free(scanPtr);
				scanPtr=head;			
			}
		}
		else
		{
			printf("Deleting list is not possible: List is Empty\n");
		}	
	}
	
	void SearchList()
	{
		int searchData; /*Data to be searched*/
		
		
		searchPtr=head;
		if(searchPtr!=NULL)
		{
			printf("Enter data to be searched from the list: ");
			scanf("%d",&searchData);
		
			
			while(searchPtr!=NULL)
		    {			
				if(searchPtr->data==searchData)
				{
					printf("%d is found in the list.\n",searchData);
					break;
				}
				else 
				{
					if(searchPtr->data!=searchData)
					{
						if(searchPtr->next==NULL )
						{
							printf("%d is not found in the list.\n",searchData);
			    			break;
						}			    	    
				    	else 
				        {
							searchPtr=searchPtr->next;
			    		}
					}				 				   
				}
			}
		}
		else
		{
			printf("Searching is not valid: List is Empty\n");
		}		
				
	}	
	
    
    int main()
    {
        int flag ;
        int choice ;
        flag = 1 ;
        
        while (flag ==1)
        {
             choice = DisplayMenu() ;
             switch(choice)
             {  case 1 :
                { 
                     CreateList() ;
                     break ;
                }
                case 2:
                {
                     InsertNode();
                     break ;
                }
                case 3:
                {
                    DeleteNode();
                    break ;
                }
                case 4:
                {
                    DisplayList() ;
                    break ;
                }
                case 5:
                {
                    DeleteList() ; /* traverse through the list and remove each element by element */
                    break ;
                }
                case 6:
                {
                    SearchList();
                    break ;
                }
                case 7:
                {
                    flag = 0 ;
                    break ;
                }
                default:
                {
                   break ;
                }
             }
        }
    }
