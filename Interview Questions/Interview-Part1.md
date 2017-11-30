# Set-1 #

1.Scope of a variable: It is the visibility of the variables. Scope of the variable defines which part of the program can access those variables. Scope can be global or local. Variables with global scope are accessable to the entire program where as variables with local scope are accessable only within that particular block of code.

2.Declaration: Declaring a variable indicates the type and size of the variable. It doesnot allocate any memory space.
               
               Example:
                        int x; //x is a variable of type integer and has size 4 bytes

  Definition: Defining a variable declares the variable as well as initializes it to some value and also allocates a memory space.
               
               Example:
                        int x = 10; //x is a variable of type integer and allocated memory storage and is initialized to value 10.

3.Declaring an array: Indicates the type of the array and also the size of the array. Size of the array must be an integer greater than zero. Size of the array indicates the number of elements that particular array can hold where as for a variable size is not declared.

              Example:  int array[10]; //array is of type integer with name 'array' and can hold 10 integer elements
                        char word[20]; //array is of type character with name 'word' and can hold 20 characters
                        int array;     //array is a single integer variable and not an array.

4.If the array is declared locally it gets created on stack. If it gets created dynamically then it is created on heap.

5.There are 4 storage class specifiers available in C language. They are,

   1)auto- all local variables are of auto storage class by default and their scope is only within the function.

          int var; // by default, storage class is auto
          auto int var;  

   2)extern- It is used to give reference to a global variable to make it visible to all the program files previously defined. 
````
/*First File:*/ 
#include <stdio.h>
int count ;
extern void write_extern();
 
main() {
   count = 5;
   write_extern();
}
Second File:
#include <stdio.h>
 
extern int count;
 
void write_extern(void) {
   printf("count is %d\n", count);
}
````
   3)static- It is used to make the local variables in a function to maintain its value between the function calls. When static is applied to the global variables it makes its scope to be within the same file.
````
#include <stdio.h>

// static int count = 0; //static global variable
 
void func() 
{
   static int count = 0;//static local variable
   /* value of 'count' persist between function calls
    * i.e count doesn't become 0 every time func() is called;
    * previous value of count remains alive
    */
   count++;
   printf("Function is called %d times\n",count);
}

int main() 
{
   printf("Calling Function :-\n");
   func();
   printf("Calling Function :-\n");
   func();
   printf("Calling Function :-\n");
   func();
   return 0;
}
````
   4)register- It is used to make the local variables to be stored in the register instead of memory. This is used only for               quick access.
````
void func()
{
register int count;
}
````

6.while() loop: It is used when you want to execute the statements within the while loop only when the condition becomes true.
   
  do while() loop: It is used when you want to execute the statements within the do while loop atleast once and later continue executing the statements only if the condition is true.

7.malloc(): It is used to allocate memory dynamically. It allocates only single block of memory and takes only one argument.
  calloc(): It is also used to allocate memory dynamically. It allocates multiple blocks of memory and takes two argument.  Additionally it also initializes the memory to zero where as malloc doesn't.

8.To create an integer array,as shown in the code below, user inputs the size of the array. Let that be 5 for suppose, then malloc creates 5*sizeof(int) that is 20 bytes of memory which sufficient to store 5 integers in an array. This is allocating memory dynamically.

````
\*Creating an array dynamically*\
#include<stdio.h>
#include <malloc.h>

main()
{

  int *array; 
  int size;
  int idx;
  
  printf("Enter the size of the array: \n");
  scanf("%d",&size);
  
  array=(int*)malloc(size*sizeof(int));//dynamically allocated size of array 
  printf("%d\n",sizeof(array));
  
  if(array==NULL)
  {
	printf("Insufficient Memory, Exiting... \n");
    return 0;
  }  
  
  printf("Enter %d numbers : ",size);
  
  for(idx=0;idx<size;idx++)
  { 
  	
    scanf("%d", &array[idx]);
  }
  
  for (idx = 0 ; idx<size; idx++)
  {
    printf("%d ", array[idx]);
  }
  
  free(array);
}
````
9.Pointers: A pointer is a variable which holds the address of another variable. It is declared with any C data type and an asterisk(*).
````
int var;   //integer variable         
int *ptr;  //integer pointer

ptr=&var;  //integer pointer holding the address of integer variable var

/* ptr holds the address of variable var where as *ptr holds the value of variable var */ 
````

10.Dangling pointer: A pointer pointing to a de-allocated memory location or non-existing object is called dangling pointer.                      The memory location pointed by dangling pointer is known as dangling reference.

11.Void pointer: A void pointer is pointer that can hold the address of a variable with any data type and can be typecasted to any type and is declared using void keyword.
````
void *ptr; //void pointer 
int a=10;
char b='c';

ptr=&a; //pointer can hold address of integer variable a
ptr=&b; //pointer can hold address of character variable b
````
Uses:
1) It can be used for implementation of generic functions in c.
2) malloc() and calloc() return void * type and this allows these functions to be used to allocate memory of any data type (just because of void *) 

12.Modular programming: Modular programming is the process of subdividing a computer program into separate functional units called modules.

   Structured Programming: It is also known as Modular Programming and a subset of procedural programming language.In Structured Programming, Programs are divided into small self contained functions.

13.Switch case statement is used to test a variable against a list of values and each value is a case and each case have statements to be executed. When the variable to be switched between values is equal to a particular value it executes that case statements. It also has an optional default case. The default case can be used for performing a task when none of the cases is true.
Use: It is faster than a nested if else statements.

14.Compiler doesnot give any error for the below code:
````
main()
     {
        int i ;
        
        switch(i)
        {
           case 1: {
                      break ;
                   }
           case 2: {
                      break ;
                   }
           default : {
                        break ;
                     }
           case 3:   {
                        break ;
                     }
           case 4:   {
                        break ;
                     }
                    
        }
     }
````

# Set-2 #

1.The default case must be at the end of the switch statement and no break is needed in the default case whereas if the default case is put in between the other cases then it needs to have break statement otherwise the control jumps to the subsequent case and executes the statements till it reaches a break statement.

2.While opening a file, the programmer has to give the filename and the operation to be performed.

 Checks to be performed- to check if the fopen() is not returning a null pointer and if it does then print an error message by using strerror(errno). Depending on the errno the strerror() prints an error message then the programmer can take appropriate action based on the errno value.

3.fopen() is the function call to open file.
````
FILE * ptr;
ptr=fopen("filename","mode");
````
First parameter is the name of the file to be opened and second parameter is the mode of operation to be performed on the file.

Different modes in fopen API:

* "r"- to read the file and the file must exist.
* "w"- creates a new file to write but if the file already exist then its contents are erased and it becomes empty to write into      it.
* "a"-appends to the existing file or creates new file to write if it doesnot exist.
* "r+"-opens the file to read and also write, file must exist.
* "w+"- creates a new file to write as well as read.
* "a+"-opens a file to read and append to the file

4.Enumeration is the user defined data type which consists of integral constants. It is use to assign names to integral constants.
````
enum weekdays{Mon,Tue,Wed,Thurs,Fri}

enum weight{ rosy=42, rob=56, tom=67}
````

5.If the first parameter of the fprintf() is replaced by stdout, it prints the output on the console instead of writing the output into the file.

6.Recursion is term used when a function calls itself. It is used to replace complex iterative code.
````
#include<stdio.h>

long int factorial(int x)
{
	long int fact;
	
	if(x==0)
	{
		fact=1;
		return fact;
	}
	
	fact=x*factorial(x-1);
	return fact;
}

int main()
{
	int n;
	long int result;
	
	printf("Enter the value whose factorial is to be found: \n");
	scanf("%d",&n);
	
	result=factorial(n);
	
	printf("Factorial of %d= %ld\n",n,result);
}
````

7.Bitwise operators perform bit operations. Decimal values are converted into binary values (sequence of bits) and these operators perform bit operations on these bits. 

Bitwise AND(&), bitwise OR(|), bitwise NOT(~), XOR(^), Left shift(<<), Right shift(>>)

Example: A&B, A|B, ~A, A^B, A<<1, A>>1

8.Variable parameters: Defining a function to take variable number of parameters instead of fixed pre-defined parameters. The function should be declared in stdarg.h header. This introduces va_list, a new type and three different functions va_start, va_arg and va_end to operate on elements of this va_list type.

* va_start()-initializes the list with total number of parameters
* va_arg()-accesses each parameter
* va_end()-cleans the memory assigned to the va_list

Example: 
````
int func(int num, ...) 
{
   //num is the total number of parameters the programmer wants to pass, (...) represents the parameters to be passed
}
main()
{
   int result;
   result=func(4, 1,2,3,4);
}     
````

9.Command line arguments are the arguments that are passed to the main function and the input is given from the command line.
```   
int main(int argc, char *argv[]) 
```   
  argc- argument count: number of command line arguments
  argv[]-argument vector: this is an array of character pointers that points the list of arguments.
   
  If argc>0 then argv[0] is the name of the program and remaining elements are the command line arguments.

Example:
````
#include<stdio.h>

/*Multiplication of two numbers using commandline arguments*/
int main(int argc, char *argv[])
{
	int result;
	
	printf("argv[0]:%s\n",argv[0]);
	
	if(argc!=3)
	{
		printf("Please enter two numbers to be multiplied in the command line.\n");
	}
	
	printf("Total number of arguments=%d\n",argc);
	
	result=atoi(argv[1])*atoi(argv[2]);
	
	printf("Multiplication of %d and %d = %d\n",atoi(argv[1]),atoi(argv[2]),result);	
}
````

10.The program can be compiled and executed without an error even with empty main() implementation. On execution, there would be no output. If the programmer wants the output with an empty main() then gcc __attributes__((constructors)) can be used which calls the functions before main().
````
#include<stdio.h>

void func(void)__attribute__((constructor));

void func(void)
{
	int a,b,c;
	printf("Main is empty.\n");
	
	printf("Enter values for a and b:\n");
	scanf("%d %d",&a,&b);
	c=a+b;
	printf("c=%d\n",c);
	
}

main()
{
	
}
````

11.Structure is a user defined data type which holds a collection of values of different data types under a single name where as C is structured programming language as it can be divided into logical structures or functions or modules for easy understanding and implementation.

12.While declaring variables in a function, if static keyword is used then the value of the variables is retained between function calls, no matter how many times ever the function in which it is contained is called.

13.Double data type should be used to get accurate value while calculating the flight path.

14.Advantages of linked lists over arrays:
	1) Insertion/deletion is easy.
	2) Dynamic size.
	3) Linked list can hold different data types.    

15.Actual parameters: Parameters which appear in the function calls.
   Formal Parameters: Parameters which appear in the function declarations.
````
void func(int a, int b) //a,b are formal parameters
{
}

main()
{
int x,y;
func(x,y); // x,y are actual parameters
}
````
     
