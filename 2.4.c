#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

const char* childProcess() {
  char *name = malloc(20);
  printf("Enter name : ");
  scanf("%[^\n]%*c", name);
  
  return name;
}

void parentProcess() {
  printf("Waiting for child to finish\n");
  wait(NULL);
  printf("Job is done\n");
}

int main(void) {
  for(int i = 0; i < 4; i++) {
    pid_t pid = fork();

    if (pid == 0) {
      printf("The given name is : %s\n", childProcess());
      exit(EXIT_SUCCESS);
    } else if (pid > 0) {
      parentProcess();
    }
  }
  return 0;
}
