#include<stdio.h>

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int pri;
    int completed;
};

int main()
{
    int n, i;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of process: ");
    scanf("%d", &n);

    struct process p[n];

    for(i = 0; i < n; i++)
    {
        printf("\nEnter arrival time, burst time and priority of P%d: ", i + 1);
        scanf("%d%d%d", &p[i].arrival_time, &p[i].burst_time, &p[i].pri);
        p[i].pid = i + 1;
        p[i].completed = 0;
    }

    int completed_count = 0;
    int current_time = 0;

    while(completed_count < n)
    {
        int index = -1;
        int highest_priority = 9999;

        for(i = 0; i < n; i++)
        {
            if(p[i].arrival_time <= current_time && p[i].completed == 0)
            {
                if(p[i].pri < highest_priority)
                {
                    highest_priority = p[i].pri;
                    index = i;
                }
                else if(p[i].pri == highest_priority)
                {
                    if(p[i].arrival_time < p[index].arrival_time)
                    {
                        index = i;
                    }
                }
            }
        }

        if(index == -1)
        {
            current_time++;
        }
        else
        {
            current_time += p[index].burst_time;
            p[index].completion_time = current_time;
            p[index].turn_around_time = p[index].completion_time - p[index].arrival_time;
            p[index].waiting_time = p[index].turn_around_time - p[index].burst_time;
            p[index].completed = 1;

            avg_wt += p[index].waiting_time;
            avg_tat += p[index].turn_around_time;
            completed_count++;
        }
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nPID\tAT\tBT\tPRI\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].pri,
               p[i].completion_time,
               p[i].turn_around_time,
               p[i].waiting_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turn Around Time: %.2f\n", avg_tat);

    return 0;
}
