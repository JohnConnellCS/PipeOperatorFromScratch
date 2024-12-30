#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  //ensure at least one command to run
  if(argc == 1){
    errno = EINVAL;
    exit(errno);
  }
  int pipefd[2];
  //go through each command argument
  for(int i = 1; i < argc; i++){
	//check if pipe failed
    if(pipe(pipefd) == -1)
      exit(errno);
    int PID = fork();
    if(PID < 0){
      exit(errno);
    }else if(PID == 0){
      //last argument should not have stdout altered
      if(i < argc - 1)
        dup2(pipefd[1], 1);
      close(pipefd[0]);
      close(pipefd[1]);
      execlp(argv[i], argv[i],(char *) NULL);
      exit(errno);
    }else{
      int status;
      waitpid(PID, &status, 0);
      if(WEXITSTATUS(status) != 0)
		exit(WEXITSTATUS(status));
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      close(pipefd[0]);
    }
  }
  return 0;
}

