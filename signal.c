#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

static void sighandler(int signo){
  int fd;
  char * message = "exited due to sigint\n";
  if(signo == SIGINT){
    fd = open("file", O_CREAT | O_WRONLY | O_APPEND, 0644);
    write(fd,&message, strlen(message));
    printf("exited due to sigint\n");
    close(fd);
    exit(0);
  }
  if(signo==SIGUSR1){
    printf("parent pid: %d\n",getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while(1){
    printf("pid: %d\n",getpid());
    sleep(1);
  }
}
