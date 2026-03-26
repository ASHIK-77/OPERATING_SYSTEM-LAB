#include<stdio.h>
int main(){
    int frames,pages,i,j,hit=0,miss=0;

    printf("Enter the number of pages : ");
    scanf("%d",&pages);

    printf("Enter the frame number: ");
    scanf("%d",&frames);

    printf("Enter the reference string: ");

    int ref[pages], frame[frames];

    for(i=0;i<pages;i++){
        scanf("%d",&ref[i]);
    }

    // FIXED HERE
    for(j=0;j<frames;j++){
        frame[j] = -1;
    }

    int index=0;

    for(i=0;i<pages;i++){
        int found=0;

        for(j=0;j<frames;j++){
            if(frame[j]==ref[i]){
                found=1;
                hit++;
                break;
            }
        }

        if(!found){
            frame[index]=ref[i];
            miss++;
            index=(index+1)%frames;
        }

        printf("\n");
        for(int k=0;k<frames;k++){
            if(frame[k]==-1)
                printf("-\t");
            else
                printf("%d\t",frame[k]);
        }
    }

    printf("\nTotal page miss = %d",miss);
    printf("\nTotal page hit : %d",hit);

    return 0;
}
