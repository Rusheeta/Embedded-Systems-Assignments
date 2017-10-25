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
	
	}
	
	void DeleteNode()
	{		
		
	}
	
	void DisplayList()
	{
		printf("List is Empty\n");
	}
	
	void DeleteList()
	{
	
	}
	
	void SearchList()
	{
				
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
