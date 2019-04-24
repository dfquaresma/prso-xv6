#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int prio = atoi(argv[1]);
  int pid  = getpid();

  setpriority(pid, prio);
  printf(2, "pid:%d prio:%d\n$ ", pid, prio);
  int count = 0;
  while (1) {
    count = (count + 1) % 1000;
  }

  return exit();

}