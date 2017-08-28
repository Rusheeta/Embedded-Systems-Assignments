#include<stdio.h>
#include<conio.h>
void main()
{
int N=100,i,j;
clrscr();
printf("Printing odd numbers below 100 in ascending order\n");
for(i=0;i<=N;i++)
{
if(i%2!=0)
printf("%d ",i);
}
printf("\n");
printf("\nPrinting odd numbers below 100 in descending order\n");
for(j=N;j>=0;j--)
{
if(j%2!=0)
printf("%d ",j);
}
getch();
}