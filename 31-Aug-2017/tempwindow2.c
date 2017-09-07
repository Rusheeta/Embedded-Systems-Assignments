#include<stdio.h>
#include<stdlib.h>
#include<time.h>

 double * simulateTempSensor()
{
	
    
int i;
static double val[100]={};
srand((unsigned)time(NULL));
    for (i=0;i<60;i++)
    {
	
    val[i]=rand();
       
       printf("val[%d]=%lf\n",i,val[i]);
       
      
   }
    
 return val;
  
}

double Max(double A[100],int n) //to calculate min of temperatures of each window
{
int i=0;
double max;
max=A[0];
while(i<n)
{
if(A[i]>=max)
max=A[i];
i++;
}
return max;
}

double Min(double B[100],int n) //to calculate min of temperatures of each window
{
int j=0;
double min=0;
min=B[0];
//printf("j=%d\n",j);
for(j=0;j<n;j++)
{
if(B[j]<=min)
min=B[j];
}
return min;
}

double Average(double C[100],int n) // to calculate average of the temperatures of each window
{
int k=0;
double t=0;
double Avg;
while(k<n)
{
t=t+C[k];
k++;
}
Avg=t/n;
return Avg;
}

double display(double D[100],int a) //to display max, min and average of temperatures for each window
{
double max=0,min=0,avg=0;
max=Max(D,a);
min=Min(D,a);
avg=Average(D,a);
printf("\nMaximum temperature for this window is %f\n",max);
printf("\nMinimum temperature for this window is %f\n",min);
printf("\nAverage is %f\n",avg);
return max,min,avg;
}


int windowType(double T[100],int d,int b)
	{
double A[100];
int a=0;

for(a=0,b=0+b;a<d,b<d;a++,b++)
{
	A[a]=T[b];
	
	printf("%f ",A[a]);	
	
}

display(A,a);
return b;
}





double main()
{
int data=0,data1=0,data2=0,data3=0,data4=0,tempdata;
//float temp_data;
double Temp[100]={ };
//double *Temp;
double Temp_five[5]={ };
double Temp_ten[10]={ };
double Temp_fifteen[15]={ };
double *random;
random=simulateTempSensor();

while(data<60)
{
//scanf("%f",&temp_data);


Temp[data]=*(random+data);
printf("Temp[%d]=%lf\n",data,*(random+data));
data++;
data1=data;

if(data1%5==0)
{

	printf("5min window:\n");

data2=windowType(Temp,data1,data2);
}

if(data1%30==0)
{
	
printf("30min window:\n");
	
data3=windowType(Temp,data1,data3);	
}
if(data1%60==0)
{
	printf("60min window:\n");

data4=windowType(Temp,data1,data4);	
}
}

}
