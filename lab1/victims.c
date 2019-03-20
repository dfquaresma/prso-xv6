#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{   
  int pid = 1;
  int victims = 1;
  int pidgodfather = getpid();
  printf(1, "PID Godfather %d\n", pidgodfather);
  while (pid != 0 && victims < 100) {
    pid = fork();
    sleep(10);
    victims++;
  }
  sleep(60000);
  return exit();
}
