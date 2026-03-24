#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sstf(int req[], int n, int head) {
    int visited[n];
    for(int i = 0; i < n; i++) visited[i] = 0;

    int total_seek = 0, current = head;

    printf("\nSSTF Head Movement:\n%d", current);

    for(int i = 0; i < n; i++) {
        int min = 100000, index = -1;

        for(int j = 0; j < n; j++) {
            if(!visited[j]) {
                int dist = abs(current - req[j]);
                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        total_seek += min;
        current = req[index];
        printf(" -> %d", current);
    }

    printf("\nTotal Seek Time (SSTF): %d\n", total_seek);
}

void cscan(int req[], int n, int head, int disk_size) {
    int above[n], below[n];
    int a = 0, b = 0;

    for(int i = 0; i < n; i++) {
        if(req[i] >= head) above[a++] = req[i];
        else below[b++] = req[i];
    }

    sort(above, a);
    sort(below, b);

    int total_seek = 0, current = head;

    printf("\nC-SCAN Head Movement:\n%d", current);

    for(int i = 0; i < a; i++) {
        total_seek += abs(current - above[i]);
        current = above[i];
        printf(" -> %d", current);
    }

    if(b > 0) {
        if(current != disk_size - 1) {
            total_seek += abs((disk_size - 1) - current);
            current = disk_size - 1;
            printf(" -> %d", current);
        }

        total_seek += (disk_size - 1);
        current = 0;
        printf(" -> %d", current);

        for(int i = 0; i < b; i++) {
            total_seek += abs(current - below[i]);
            current = below[i];
            printf(" -> %d", current);
        }
    }

    printf("\nTotal Seek Time (C-SCAN): %d\n", total_seek);
}

void look(int req[], int n, int head) {
    int above[n], below[n];
    int a = 0, b = 0;

    for(int i = 0; i < n; i++) {
        if(req[i] >= head) above[a++] = req[i];
        else below[b++] = req[i];
    }

    sort(above, a);
    sort(below, b);

    int total_seek = 0, current = head;

    printf("\nLOOK Head Movement:\n%d", current);

    for(int i = 0; i < a; i++) {
        total_seek += abs(current - above[i]);
        current = above[i];
        printf(" -> %d", current);
    }

    for(int i = b - 1; i >= 0; i--) {
        total_seek += abs(current - below[i]);
        current = below[i];
        printf(" -> %d", current);
    }

    printf("\nTotal Seek Time (LOOK): %d\n", total_seek);
}

int main() {
    int choice;

    do {
        int n, head, disk_size;

        printf("\n===== Disk Scheduling Menu =====\n");
        printf("1. SSTF\n");
        printf("2. C-SCAN\n");
        printf("3. LOOK\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 3) {
            printf("Enter number of disk requests: ");
            scanf("%d", &n);

            int req[n];
            printf("Enter the disk request sequence: ");
            for(int i = 0; i < n; i++)
                scanf("%d", &req[i]);

            printf("Enter initial head position: ");
            scanf("%d", &head);

            switch(choice) {
                case 1:
                    sstf(req, n, head);
                    break;

                case 2:
                    printf("Enter disk size: ");
                    scanf("%d", &disk_size);
                    cscan(req, n, head, disk_size);
                    break;

                case 3:
                    look(req, n, head);
                    break;
            }
        }

    } while(choice != 4);

    printf("Exiting program...\n");

    return 0;
}
