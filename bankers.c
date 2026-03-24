#include <stdio.h>

int main() {
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m];
    int available[m];
    int finish[n], safeSeq[n];

    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Max Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for (int j = 0; j < m; j++) {
        scanf("%d", &available[j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\n\nProcess\tAllocation\tMax\t\tNeed\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t", i);

        for (int j = 0; j < m; j++)
            printf("%d ", allocation[i][j]);

        printf("\t\t");

        for (int j = 0; j < m; j++)
            printf("%d ", max[i][j]);

        printf("\t\t");

        for (int j = 0; j < m; j++)
            printf("%d ", need[i][j]);

        printf("\n");
    }

    printf("\nAvailable: ");
    for (int j = 0; j < m; j++)
        printf("%d ", available[j]);
    printf("\n");

    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;
    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int possible = 1;

                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        possible = 0;
                        break;
                    }
                }

                if (possible) {
                    for (int j = 0; j < m; j++) {
                        available[j] += allocation[i][j];
                    }

                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("\nSystem is NOT in a safe state.\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("P%d", safeSeq[i]);
        if (i != n - 1)
            printf(" -> ");
    }
    printf("\n");

    return 0;
}
