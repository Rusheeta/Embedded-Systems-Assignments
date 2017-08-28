#include<stdio.h>
#include<conio.h>
void main()
{
int n,i,j,P[500],counter=0;
clrscr();
printf("Enter an integer to be factorized: ");
scanf("%d",&n);
printf("Factors of %d=",n);
for(i=1;i<=n;i++)
{
if(n%i==0)
{
printf("%d,",i);
P[counter]=i;
counter++;
}
}
//printf("%d",counter);
printf("\nValidated output sets:\n");
for(j=0;j<=counter-1;j++)
{
printf("Set %d=(%d,%d)\n",j+1,P[j],P[counter-1]);
counter--;
}
getch();
}