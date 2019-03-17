#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{   
  int pid = 1;
  while (pid != 0) {
    pid = fork();
    sleep(1);
  }
  sleep(10);
  return exit();
}
