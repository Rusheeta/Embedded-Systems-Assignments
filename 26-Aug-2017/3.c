#include<stdio.h>
#include<conio.h>
void main()
{
int X,Y;
clrscr();
printf("Enter a number X: \n");
scanf("%d",&X);
printf("Enter a number Y: \n");
scanf("%d",&Y);
if(X%Y==0)
{
printf("X=%d is divisible by Y=%d",X,Y);
}
else
{
printf("X=%d is not divisible by Y=%d",X,Y);
}
getch();
}
