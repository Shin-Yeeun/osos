#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <err.h>
#include <sys/types.h>
#include <sys/wait.h>
int pipes[2];

void parent_proc(){
    ssize_t target;
    ssize_t solution;
    


}
void child_proc(){
  
}

int main(int argc, char * args[]){
  pid_t target_pid ;
  pid_t solution_pid;

  int exit_code ;

  for(int i=0; i<argc; i++){
    printf("args[%d] : %s\n",i,args[i]);
  }

  target_pid = fork() ;
  solution_pid = fork();
  
  if (target_pid == 0) {
    execl("/usr/bin/gcc", "gcc", "-o", "target",args[4],  (char *)NULL);
  }

  else {
    wait(0);
    //freopen("input.txt", "r", stdout);
    execl("./target","target",(char *)NULL);

  }

  
 
  if(solution_pid == 0){
    execl("/usr/bin/gcc", "gcc", "-o", "solution", args[5], (char *) NULL);
  }
  else{
    
    //freopen("input.txt","r",stdout);
    execl("./solution","solution",(char*)NULL);
  }

  wait(&exit_code) ;
  exit(0) ;
  
}