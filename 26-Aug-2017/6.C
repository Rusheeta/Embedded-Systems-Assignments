#include<stdio.h>
#include<conio.h>
void main()
{
int N,a,Lar,sm,i,c;
char Ans;
clrscr();
do
{
printf("Enter how many numbers you need:");
scanf("%d",&N);
printf("Enter a number:");
scanf("%d",&a);
Lar=a;
sm=a;
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
printf("%d is the smallest number.\n",sm);
printf("Do you wish to continue the same procedure, enter (Y/N):");
scanf(" %c",&Ans);
if(Ans=='N')
printf("Press any key to 'Exit'");
}while(Ans=='Y');

getch();
}
