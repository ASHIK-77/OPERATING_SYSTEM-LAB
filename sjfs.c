#include<stdio.h>

struct process{
    int pid, at, bt, ct, tat, wt, completed;
};

int main(){
    int n, i, j, completed = 0, current_time = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for(i=0;i<n;i++){
        printf("Enter AT and BT for P%d: ", i+1);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].pid = i+1;
        p[i].completed = 0;
    }

    while(completed < n){
        int min_bt = 9999, pos = -1;

        // Find shortest job among arrived processes
        for(i=0;i<n;i++){
            if(p[i].at <= current_time && p[i].completed == 0){
                if(p[i].bt < min_bt){
                    min_bt = p[i].bt;
                    pos = i;
                }
            }
        }

        // If no process available → CPU idle
        if(pos == -1){
            current_time++;
        }
        else{
            current_time += p[pos].bt;
            p[pos].ct = current_time;
            p[pos].tat = p[pos].ct - p[pos].at;
            p[pos].wt = p[pos].tat - p[pos].bt;

            avg_wt += p[pos].wt;
            avg_tat += p[pos].tat;

            p[pos].completed = 1;
            completed++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid, p[i].at, p[i].bt,
        p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage WT = %.2f", avg_wt/n);
    printf("\nAverage TAT = %.2f\n", avg_tat/n);

    return 0;
}
