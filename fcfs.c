#include <stdio.h>

struct process {
    int pid, at, bt, ct, tat, wt;
};

int main() {
    int n, i, j;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n], temp;

    // Input
    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time of P%d: ", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].pid = i + 1;
    }

    // Sort based on Arrival Time
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int time = 0;

    // FCFS Calculation
    for(i = 0; i < n; i++) {

        if(time < p[i].at) {
            time = p[i].at;  // CPU idle
        }

        p[i].ct = time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        time = p[i].ct;

        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }

    // Output Table
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    // Gantt Chart
    printf("\nGantt Chart:\n");

    printf("%d", p[0].at);
    for(i = 0; i < n; i++) {
        printf(" | P%d | %d", p[i].pid, p[i].ct);
    }
    printf("\n");

    return 0;
}
