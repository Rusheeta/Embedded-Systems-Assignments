#include<stdio.h>
#include<malloc.h>

typedef struct node 
    {
       int data ;
       struct node *left ;
       struct node *right ;
    } NODE ;
    
    /* Declare head of the list as a Global Variable */
    
    NODE  *head= NULL ;    /*pointer to point to the start of the linked list*/
    NODE  *tail= NULL ;    /*pointer to point to the end of the linked list*/
    NODE  *scanPtr= NULL ; /*pointer to traverse from the start to end of the linked list*/
    NODE  *nodePtr= NULL ; /*pointer to point to newly created node of the linked list*/
    NODE  *dispFwdPtr=NULL;/*pointer to traverse forward and display the list in the forward direction*/
    NODE  *dispRevPtr=NULL;/*pointer to traverse reverse and display the list in the reverse direction*/
    NODE  *searchPtr=NULL; /*pointer to traverse and search for data in the list*/
    NODE  *newNodePtr= NULL ;/*pointer to point to the new node created to insert into the list*/
	NODE  *scanNextPtr=NULL ;/*Pointer to point to next node of scanPtr pointing node*/
	 
    int DisplayMenu()
    {
    	int option;
    	
    	printf("\nMenu:\n");
    	printf("1.Create List\n");
    	printf("2.Insert Node\n");
    	printf("3.Delete Node\n");
    	printf("4.Display List forward\n");
    	printf("5.Display List Reverse\n");
    	printf("6.Delete List\n");
    	printf("7.Search List\n");
    	printf("8.Exit\n");
    	
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
    	    tail=nodePtr;  /*Mark the ending of the node*/
    	    scanPtr=nodePtr; 
    	    nodePtr->right=NULL;
    	    nodePtr->left=NULL;
	   	}
        else
        {
        	scanPtr->right=nodePtr; /*Link the previous node's next pointer to the newly created node*/
    		nodePtr->left=scanPtr; /*Link newly created node to the previous node */
			scanPtr=nodePtr; /*Make scanPtr point to the newly created node*/
			tail=nodePtr; /*setting tail pointer to new node after creating a new node, in this case this is the last node in the list*/
			nodePtr->right=NULL;
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
    		newNodePtr->right=NULL;
    		newNodePtr->left=NULL;
    	
    		printf("Enter data after which new node is to be inserted: ");
    		scanf("%d",&info);
    	
    		scanPtr=head;
    		scanNextPtr=scanPtr->right;
    		
    		while(scanPtr!=NULL)
        	{	
    	    	if(scanPtr->data==info)
				{
					newNodePtr->right=scanNextPtr;
					scanNextPtr->left=newNodePtr;
					scanPtr->right=newNodePtr;
					newNodePtr->left=scanPtr;
    				break;
				}	
				scanPtr=scanPtr->right;
				scanNextPtr=scanPtr->right;
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
			
			
    		
    	    if(head->data==delInfo)
			{
				scanPtr=head;
				if(head==tail)
				{
					free(scanPtr);
    				head=NULL;
    				tail=NULL;
    				scanPtr=NULL;
				}
				else
				{
					head=scanPtr->right;
					head->left=NULL;
					scanPtr->right=NULL;
					free(scanPtr);
					scanPtr=tail;
				}
				
			}	
				    	
    		else if(tail->data==delInfo)
    		{
    			scanPtr=tail;
				tail=tail->left;
				tail->right=NULL;
				scanPtr->left=NULL;
				free(scanPtr);
				scanPtr=tail;						
			}
			else
			{
				scanPtr=head;
				searchPtr=scanPtr->right;
    		    scanNextPtr=searchPtr->right;
    		
				while(searchPtr!=NULL)
				{
					if(searchPtr->data==delInfo)
					{
						scanPtr->right=searchPtr->right;
						scanNextPtr->left=searchPtr->left;
						scanPtr=tail;
						searchPtr->left=NULL;
						searchPtr->right=NULL;
						free(searchPtr);
						searchPtr=NULL;
						break;
					}
					scanPtr=scanPtr->right;
					searchPtr=searchPtr->right;
					scanNextPtr=scanNextPtr->right;
				}
			}	
		}
		else
		{
			printf("Deletion not possible: List is empty\n");
		}    	
	}
	
	void DisplayForward()
	{
		dispFwdPtr=head;		
			
		if(dispFwdPtr!=NULL)
		{
			printf("List: ");
			while(dispFwdPtr!=NULL)
			{
				printf("%d ",dispFwdPtr->data);
				dispFwdPtr=dispFwdPtr->right;
			}
		}	
		else
		{
			printf("List is Empty\n");
		}	
	}
	
	void DisplayReverse()
	{
		dispRevPtr=tail;		
			
		if(dispRevPtr!=NULL)
		{
			printf("List: ");
			while(dispRevPtr!=NULL)
			{
				printf("%d ",dispRevPtr->data);
				dispRevPtr=dispRevPtr->left;
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
				head=scanPtr->right;
				free(scanPtr);
				scanPtr=head;			
			}
			tail=NULL;
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
						if(searchPtr->right==NULL )
						{
							printf("%d is not found in the list.\n",searchData);
			    			break;
						}			    	    
				    	else 
				        {
							searchPtr=searchPtr->right;
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
                    DisplayForward() ;
                    break ;
                }
                case 5:
                {
                    DisplayReverse() ;
                    break ;
                }
                case 6:
                {
                    DeleteList() ; /* traverse through the list and remove each element by element */
                    break ;
                }
                case 7:
                {
                    SearchList();
                    break ;
                }
                 case 8:
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
