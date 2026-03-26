#include<stdio.h>
int main(){
    int frames,pages,i,j,hit=0,miss=0;

    printf("Enter the number of pages : ");
    scanf("%d",&pages);

    printf("Enter the frame number: ");
    scanf("%d",&frames);

    printf("Enter the reference string: ");

    int ref[pages], frame[frames], time[frames];

    for(i=0;i<pages;i++){
        scanf("%d",&ref[i]);
    }

    for(j=0;j<frames;j++){
        frame[j] = -1;
        time[j] = 0;
    }

    int index=0;

    for(i=0;i<pages;i++){
        int found=0;

        for(j=0;j<frames;j++){
            if(frame[j]==ref[i]){
                found=1;
                hit++;
                index++;
                time[j]=index;
                break;
            }
        }

        if(!found){
            int pos = -1;

            // check empty frame
            for(j=0;j<frames;j++){
                if(frame[j]==-1){
                    pos=j;
                    break;
                }
            }

            // apply LRU
            if(pos==-1){
                pos=0;
                for(j=1;j<frames;j++){
                    if(time[j]<time[pos]){
                        pos=j;
                    }
                }
            }

            frame[pos]=ref[i];
            miss++;
            index++;
            time[pos]=index;
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
