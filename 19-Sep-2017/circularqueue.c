#include<stdio.h> 
#define SUCCESS 1
#define FAILURE 2 
#define MAXSIZE 5 
   
int queue[MAXSIZE]={0}; 
int head = -1;
int tail = -1;
   
int AddQueue(int element)            //function to add an element into the circular queue
{
    if((head==0 && tail==(MAXSIZE-1))||tail==(head-1))
	{
		printf("Queue is full: addition cannot be done.\n");
	}      
	else if(head==-1)
	{
		head=0;
		tail=0;
		queue[tail]=element;
		return SUCCESS;
	}
    else if(tail==(MAXSIZE-1)&& head!=0)
	{
		tail=0;
		queue[tail]=element;
		return SUCCESS;
	}
	else
	{
		tail++;				
		queue[tail]=element;		    
	    return SUCCESS;
	}
	
}
   
int DeleteQueue()               //function to delete an element from circular queue
{
	int item;
	if(head==-1)
	{
		printf("Queue is empty: deletion cannot be done.\n");
		return FAILURE;		
	}
	
	printf("//head=%d\n",head);
	item=queue[head];
	queue[head]=-1;
	
	
	if(head==tail)
	{
	    head=-1;
	    tail=-1;		    
	}
	else if(head==(MAXSIZE-1))
	{				
	    head=0;	      				
	}
	else
	{    
		printf("**head=%d\n",head);
	    head++;	    
	}
		
	return item;		
}

void PrintQueue()
{
	int i;
	
	if(head==-1)
	{
		printf("Queue is Empty.\n");
		return;
	}
	
	printf("Elements in Circular Queue are:\n");
    if (tail >= head)
    {
        for (i = head; i <= tail; i++)
            printf("%d ",queue[i]);
            
        printf("\n");
    }
    else
    {
        for (i = head; i < MAXSIZE; i++)
            printf("%d ", queue[i]);
 
        for (i = 0; i <= tail; i++)
            printf("%d ", queue[i]);
        
        printf("\n");
    }	
}
   
main()
{
       int flag ;
       int choice ; /*menu choice */
       int data ;
       flag = 1 ;
      
       while(flag)
       {
           printf("1.Add \n");
           printf("2.Delete \n");
           printf("3.Print Queue \n");
           printf("4.Exit\n");
           scanf("%d", &choice);
           switch(choice)
           {
              case 1 : {
                            printf("Enter the value to added to queue: ");
                            scanf("%d", &data);
                            if(AddQueue(data)==SUCCESS)
						    {
						  	    printf("Choose option 3 to print the queue.\n");
						    }
                            break ;
                       }
                       
              case 2 : {
			                data = DeleteQueue();
							while(data!=FAILURE)
							{
							    printf("%d removed from queue \n",data);
                                break;
							}             	  
                            break; 
                       }
                       
             case 3 :  {
                            PrintQueue();
                            break ;
                       }
            case 4:    {
                            flag = 1 ;
                       }
                       
            default:   {
                            break ;
                       }
           }
        }
    }
