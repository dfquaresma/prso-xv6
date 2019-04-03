# Lab 3 - Scheduler

## Short description

Goal: Defining a new politics of scheduling processes on xv6 that works and deal with the points below.

- Standard priority on init of each process. 

- Should be possible modify the standard priority through 'nice' program.

- Processes with high priority should be preferred.

- Should there exists some mecanism to deal with starvation. More details to this on the lab description. 

- Pay attention to possible conflicts between the new scheduling policy and the 'nice' program.

## Strategy of solution 

Essencially, the scheduler aims choose a program to run. 

- The current way that the xv6 works:
  - TODO

- Our policy of working:
  - All process will have an additional attribute called currprio.
  - Periodically, all processes' currprio will be decremented by one.
  - When a process is executed, currprio returns to its original value.
  
