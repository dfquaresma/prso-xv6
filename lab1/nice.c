#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int pid = atoi(argv[1]); printf(1, " pid: %d\n", pid);
  int prio = atoi(argv[2]); printf(1, "prio: %d\n", prio);

  int oldprio = getpriority(pid);
  setpriority(pid, prio);

  printf(1, "%d\n", oldprio);
  exit();
  return 0;
}

