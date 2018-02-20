#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv){
  int status;

  pid_t cpid = fork();
  switch(cpid)
  {
    case -1:
      perror("Cannot create child\n");
      break;
    case 0:
      printf("[CHILD] My PID is %d. My parent's pid is %d\n", getpid(), getppid());
      sleep (5);
      printf("[CHILD] Bye everyone!\n");
      //As long as the parent process active is, but the child has already terminated, the child process
      //will be a zombie.
      //printf("I'm a zombie.\n");
      //Parent process terminates before child process. Init will take over.(Adopter)
      //printf("[CHILD] I think my parent(s) is(are) dead. My parent is now process %d\n",getppid());
      break;
    default:
      sleep(2);
      printf("[PARENT] My PID is %d. I am waiting for my child with ID %d.\n",getpid(), cpid);
      waitpid(cpid, &status, WUNTRACED|WCONTINUED);
      //If the parent process does not wait for its child and is active, the child process will be a zombie.
      //when the parent process terminated, init will take the child process over and kill it.
      //sleep(10);
      //printf("[PARENT] Child exited with status %d.\n", status);
      //If parents process terminated before child process then child is taken over by init. Parent does Cannot
      //sleep or wait here.
      //printf("[PARENT] Oops! I am dead\n");
      exit(0);
  }
}
