#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int pid = atoi(argv[1]);
  int prio = atoi(argv[2]);

  int oldprio;
  if (prio == 0 && *argv[2] != '0') {
    oldprio = -1;
  } else {
    oldprio = setpriority(pid, prio);
  }
  
  printf(1, "%d\n", oldprio);
  return exit();
}

