#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int pid = atoi(argv[0]);
  int prio = atoi(argv[1]);

  int oldprio = getpriority(pid);
  setpriority(pid, prio);

  printf(1, "%d", oldprio);
  exit();
  return 0;
}

