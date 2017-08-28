#include<stdio.h>
#include<conio.h>
void main()
{
int a=1,b=1,c,n,i;
clrscr();
printf("Enter the length of the series: ");
scanf("%d",&n);
printf("Fibonacci series:\n");
for(i=1;i<=n;i++)
{
printf("%d,",a);
c=a+b;
a=b;
b=c;
}
getch();
}
