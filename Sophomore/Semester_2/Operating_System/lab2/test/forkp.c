#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
  int return_code;
  int status;
  return_code = fork();

  if (return_code == 0)
  {
    printf("This is child process\n");
    return 0;
  }
  else if (return_code > 0)
  {
    // int id = wait(&status);
    printf("This is parent process, child process with returned value = %d \n", status);
    wait(NULL);
    printf("Pid of child %d\n", return_code);
    return 0;
  }
  else
  {
    printf("Error in fork\n");
    return 1;
  }
}