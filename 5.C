#include<stdio.h>
#include<conio.h>
void main()
{
int N,n,Lar,sm,i,c;
clrscr();
printf("Enter how many numbers you need:");
scanf("%d",&N);
printf("Enter a number:");
scanf("%d",&n);
Lar=n;
sm=n;
for(i=1;i<=N-1;i++)
{
printf("Enter another number:");
scanf("%d",&c);
if(c>Lar)
Lar=c;
if(c<sm)
sm=c;
}
printf("%d is the largest number.\n",Lar);
printf("%d is the smallest number.",sm);
getch();
}
