#include<stdio.h>

struct process{
    int pid, at, bt, rt, ct, tat, wt;
};

int main(){
    int n, i, tq, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for(i=0;i<n;i++){
        printf("Enter AT and BT for P%d: ", i+1);
        scanf("%d%d", &p[i].at, &p[i].bt);

        p[i].pid = i+1;
        p[i].rt = p[i].bt;   // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int done;

    while(completed < n){
        done = 1;

        for(i=0;i<n;i++){
            if(p[i].rt > 0 && p[i].at <= time){

                done = 0;

                if(p[i].rt > tq){
                    time += tq;
                    p[i].rt -= tq;
                }
                else{
                    time += p[i].rt;
                    p[i].rt = 0;
                    p[i].ct = time;
                    completed++;
                }
            }
        }

        // If no process executed → CPU idle
        if(done){
            time++;
        }
    }

    float avg_wt=0, avg_tat=0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        avg_tat += p[i].tat;
        avg_wt += p[i].wt;

        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid, p[i].at, p[i].bt,
        p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage WT = %.2f", avg_wt/n);
    printf("\nAverage TAT = %.2f\n", avg_tat/n);

    return 0;
}
