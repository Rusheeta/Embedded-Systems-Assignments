#include<stdio.h>

typedef struct node 
    {
       int data ;
       struct node *left ;
       struct node *right ;
    } NODE ;
    
    /* Declare head of the list as a Global Variable */
    
    NODE  *head ;
    NODE  *scanPtr ;
    
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
		
	}
	
	void InsertNode()
	{
		
	}
	
	void DeleteNode()
	{
		
	}
	
	void DisplayForward()
	{
		
	}
	
	void DisplayReverse()
	{
		
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
