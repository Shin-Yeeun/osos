#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
  pid_t child_pid ;
  int exit_code ;
  child_pid = fork() ;
  if (child_pid == 0) {
    
    execl("/usr/bin/gcc", "gcc", "-o", "target", "target.c", (char *) NULL);
  }
  else {
    wait(0);
    execl("./hello", 0,);
  }
  wait(&exit_code) ;
  exit(0) ;
}