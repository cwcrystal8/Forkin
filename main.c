#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>


int main(){
  printf("Hi! I'm a parent and my pid is %d\n", getpid());
  int pid1 = fork(), status;
  if(pid1){
    int pid2 = fork();
    if(pid2){
      int cpid = wait(&status);
      printf("Completed child's pid: %d | Asleep for %d seconds\n", cpid, WEXITSTATUS(status));
      printf("Parent has completed!\n");
      return 0;
    }
    else{
      printf("\tHi! I'm a child and my pid is %d\n", getpid());
      srand(time(NULL));
      int pause = 5 + (rand() % 16);
      sleep(pause);
      printf("\tChild %d has completed!\n",getpid());
      return pause;
    }
  }
  else{
    printf("\tHi! I'm a child and my pid is %d\n", getpid());
    srand(time(NULL));
    int pause = 5 + (rand() % 16);
    sleep(pause);
    printf("\tChild %d has completed!\n",getpid());
    return pause;
  }
  return 0;
}
