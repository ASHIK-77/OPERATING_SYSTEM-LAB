#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int full=0;
int empty;
int x=0;
void producer(){
--mutex;
++full;
--empty;
x++;
printf("producer produces item %d\n",x);
++mutex;
}
void consumer(){
--mutex;
--full;
++empty;
printf("consumer consumes item %d\n",x);
x--;
++mutex;
}
int main(){
printf("Enter the buffer size:");
scanf("%d",&empty);

int i,n;
printf("\n 1. Producer \n 2. Consumer \n 3.Exit \n");

for(i=1;i>0;i++){
printf("enter the choice: ");
scanf("%d",&n);

switch(n){
case 1:
if((mutex==1)&&(empty!=0)){
producer();
}
else{
printf("buffer is full\n");
}
break;

case 2:
if((mutex==1)&&(full!=0)){
consumer();
}
else{
printf("buffer is empty\n");
}
break;

case 3:
printf("exiting..\n");
exit(0);
break;
}
}
}



