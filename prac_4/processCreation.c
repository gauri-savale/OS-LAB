#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
pid_t pid;

printf("Parent process started\n");
printf("Parent  pid : %d\n",getpid());

pid = fork();
if(pid <0){
printf("process creation failed");
}else if ( pid == 0 ){
printf("\n child pid : %d\n",getpid());
printf("\n parent pid : %d\n",getppid());
execl("/bin/ls","ls","-1",NULL);
printf("exec failed");
}else{
wait(NULL);
printf("\n child process  completed\n ");
printf("parent process  exiting");
} 
return 0;
}

