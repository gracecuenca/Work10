#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    printf("exited due to sigint\n");
    exit(0);
  }
  if(signo==SIGUSR1){
    printf("pid: %d\n",getpid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while(1){
    int pid = getpid();
    kill(pid, SIGUSR1);
    sleep(1);
  }
}
