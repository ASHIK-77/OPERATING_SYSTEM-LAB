#include <stdio.h>

struct process {
    int pid, at, bt, pri, ct, tat, wt, done;
};

int main() {
    int n, i, time = 0, completed = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    int gantt[n], gt[n + 1], k = 0;

    for(i = 0; i < n; i++) {
        printf("Enter AT, BT and Priority of P%d: ", i + 1);
        scanf("%d%d%d", &p[i].at, &p[i].bt, &p[i].pri);
        p[i].pid = i + 1;
        p[i].done = 0;
    }

    gt[0] = 0;

    while(completed < n) {
        int index = -1;

        for(i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].done == 0) {
                if(index == -1 ||
                   p[i].pri < p[index].pri ||
                   (p[i].pri == p[index].pri && p[i].at < p[index].at)) {
                    index = i;
                }
            }
        }

        if(index == -1) {
            time++;
        } else {
            gantt[k] = p[index].pid;
            time += p[index].bt;
            gt[k + 1] = time;
            k++;

            p[index].ct = time;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].done = 1;

            avg_wt += p[index].wt;
            avg_tat += p[index].tat;
            completed++;
        }
    }

    printf("\nPID\tAT\tBT\tPRI\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].pri,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    printf("\nGantt Chart:\n");
    for(i = 0; i < k; i++) {
        printf("|  P%d  ", gantt[i]);
    }
    printf("|\n");

    printf("%d", gt[0]);
    for(i = 1; i <= k; i++) {
        printf("      %d", gt[i]);
    }
    printf("\n");

    return 0;
}
