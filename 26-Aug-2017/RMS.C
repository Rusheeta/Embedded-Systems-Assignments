#include<stdio.h>
#include<conio.h>
#include<math.h>
double RootMeanSquare(int n)
{
long i=1,sum=0,tsum=0,Vol;
float Avg;
double RMS;
while(i<=n)
{
scanf("%ld",&Vol);
printf("Voltage=%ld\n",Vol);
sum=Vol*Vol;
printf("sum=%ld\n",sum);
tsum=tsum+sum;
printf("tsum=%ld\n",tsum);
i++;
}
Avg=tsum/n;
printf("avg=%f\n",Avg);
RMS=sqrt(Avg);
printf("rms=%lf\n",RMS);
return RMS;
}

void main()
{
int ph,j,k,n;
double R;
clrscr();
printf("Enter the number of voltages: \n");
scanf("%d",&n);
printf("Enter number of phases: \n");
scanf("%d",&ph);
for(j=1;j<=ph;j++)
{
printf("Enter the peak values for phase %d: \n",j);
R=RootMeanSquare(n);
printf("RMS voltage of phase %d= %lf\n",j,R);
}
getch();
}