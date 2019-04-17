#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{   
  int prio = atoi(argv[1]);
  int pid  = getpid();
  setpriority(pid, prio);
  
  while (1) {
      sleep(100);
      printf(1, "%d\n$ ", prio);
  }

  return exit();


}
