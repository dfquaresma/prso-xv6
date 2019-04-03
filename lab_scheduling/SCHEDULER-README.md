# Laboratory 3 - Scheduler

## Strategy to scheduler algorithm

Defining a new politics of scheduling processes on xv6.

### Points to consider

- Standard priority on init of each process. 

- Should be possible modify the standard priority through 'nice' program.

- Processes with high priority should be preferred.

- Should there exists some mecanism to deal with starvation. More details to this on the lab description. 

- Pay attention to possible conflicts between the new scheduling policy and the 'nice' program.