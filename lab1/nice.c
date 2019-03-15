#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int oldprio = setpriority(atoi(argv[0]), atoi(argv[1]));
  printf(1, "%d", oldprio);
  exit();
  return 0;
}

