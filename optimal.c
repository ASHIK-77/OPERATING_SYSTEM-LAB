#include<stdio.h>

int main(){
    int frames, pages, i, j, hit = 0, miss = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &pages);

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    int ref[pages], frame[frames];

    printf("Enter the reference string: ");
    for(i = 0; i < pages; i++){
        scanf("%d", &ref[i]);
    }

    // Initialize frames
    for(i = 0; i < frames; i++){
        frame[i] = -1;
    }

    for(i = 0; i < pages; i++){
        int found = 0;

        // Check for HIT
        for(j = 0; j < frames; j++){
            if(frame[j] == ref[i]){
                found = 1;
                hit++;
                break;
            }
        }

        // If MISS
        if(!found){
            int pos = -1;

            // Step 1: Check for empty frame
            for(j = 0; j < frames; j++){
                if(frame[j] == -1){
                    pos = j;
                    break;
                }
            }

            // Step 2: If no empty frame → apply Optimal
            if(pos == -1){
                int far = -1;

                for(j = 0; j < frames; j++){
                    int k;

                    for(k = i + 1; k < pages; k++){
                        if(frame[j] == ref[k]){
                            break;
                        }
                    }

                    // If page not used again
                    if(k == pages){
                        pos = j;
                        break;
                    }

                    // Choose farthest use
                    if(k > far){
                        far = k;
                        pos = j;
                    }
                }
            }

            frame[pos] = ref[i];
            miss++;
        }

        // Display frames
        printf("\n");
        for(j = 0; j < frames; j++){
            if(frame[j] == -1)
                printf("-\t");
            else
                printf("%d\t", frame[j]);
        }
    }

    printf("\n\nTotal Page Hits = %d", hit);
    printf("\nTotal Page Misses = %d\n", miss);

    return 0;
}
