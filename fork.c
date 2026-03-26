#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid;
    pid = fork();

    if(pid < 0){
        perror("FORK FAILED"); 
        return 1;
    }
    else if(pid == 0){
        printf("CHILD PROCESS\n");
        printf("CHILD PID: %d\n", getpid());
        printf("PARENT PID:%d\n",getppid());
    }
    else{
        printf("PARENT PROCESS\n");
        printf("PARENT PID: %d\n", getpid());
        printf("CHILD PID: %d\n", pid);
        sleep(20);
    }

    return 0;
}
