#include "types.h"
#include "user.h" 

int main(int argc, char *argv[]) 
{
    int pid = atoi(argv[1]);
    printf(1, "%d\n", getusage(pid));
    return exit();
}
