#include <stdio.h>

int main() {
    int n, i, tq, time = 0, done, completed = 0, k = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n], ct[n];
    int gantt[100], gtime[101];
    float avg_wt = 0, avg_tat = 0;

    for(i = 0; i < n; i++) {
        printf("Enter burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    gtime[0] = 0;

    while(completed < n) {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                done = 0;
                gantt[k] = i + 1;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    tat[i] = ct[i];
                    wt[i] = tat[i] - bt[i];
                    rt[i] = 0;
                    completed++;
                }

                gtime[++k] = time;
            }
        }
        if(done) break;
    }

    printf("\nProcess\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, bt[i], ct[i], tat[i], wt[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage WT = %.2f\n", avg_wt / n);
    printf("Average TAT = %.2f\n", avg_tat / n);

    printf("\nGantt Chart:\n|");
    for(i = 0; i < k; i++) {
        printf(" P%d |", gantt[i]);
    }

    printf("\n0");
    for(i = 1; i <= k; i++) {
        printf("   %d", gtime[i]);
    }

    return 0;
}