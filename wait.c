#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t pid;
    pid = fork();

    if(pid < 0){
        perror("FORK FAILED"); 
        return 1;
    }
    else if(pid == 0){
        printf("PCCSL407\n");}
    else{
        wait(NULL);
        printf("OPERATING SYSTEM LAB\n");
        sleep(20);
    }

    return 0;
}
