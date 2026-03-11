#include<stdio.h>
struct process{
int pid;
int arrival_time;
int burst_time;
int completion_time;
int turn_around_time;
int waiting_time;
};
int main()
{
int n,i,j;
float avg_wt=0,avg_tat=0;
printf("Enter the number of process : ");
scanf("%d",&n);
struct process p[n];
for(i=0;i<n;i++)
{
 printf("\nEnter the arrival time and burst time of p%d \n",i+1);
 scanf("%d%d",&p[i].arrival_time,&p[i].burst_time);
 p[i].pid=i+1;
 }for(i = 0; i < n - 1; i++)
{
for(j = i + 1; j < n; j++)
{
if(p[i].arrival_time > p[j].arrival_time)
{
struct process temp = p[i];
p[i] = p[j];
p[j] = temp;
}
}
}
int current_time = 0;
for(i = 0; i < n; i++)
{
if(current_time < p[i].arrival_time)
current_time = p[i].arrival_time;

current_time += p[i].burst_time;
p[i].completion_time= current_time;
p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;

avg_wt += p[i].waiting_time;
avg_tat+=p[i].turn_around_time;
}
avg_tat/=n;
avg_wt /= n;

printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

for(i = 0; i < n; i++)
{
printf("%d\t%d\t%d\t%d\t%d\t%d\n",
p[i].pid,
p[i].arrival_time,
p[i].burst_time,
p[i].completion_time,
p[i].turn_around_time,
p[i].waiting_time);
}

printf("\nAverage Waiting Time: %.2f\n", avg_wt);
printf("\nAverage Turn Around Time: %.2f\n", avg_tat);
printf("\n\tGant chart\n");
printf("|");
for(i=0;i<n;i++)
{
printf("\tp%d|\t",p[i].pid);
}printf("\n");
printf("0");
for(i=0;i<n;i++)
{

 printf("\t  %d\t",p[i].completion_time);
 }printf("\n");
return 0;
}

