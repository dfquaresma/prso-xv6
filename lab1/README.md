# Laboratory 1 - System calls and interrupts
In that lab, we practice the implementation of system calls and interrupts. The purposes of it is to understand the system call execution flow and its implementation, how a process is scheduled to run and finally how interrupts works. 

The tasks were:
- Print each system call when invoked.
- Implement inicially two sistem call
  - Add system call [getpriority](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/proc.c#L538): to retrieve the priority of a process.
    - We had to update the process structure, adding a prio attribute.
  - Add system call [setpriority](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/proc.c#L554): to update the priority of a process.
  - Add [nice.c](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/nice.c) to use those system calls.
- Implement a system call that returns how many times a process run 
  - Add system call [getusage](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/proc.c#L571): to retrieve the usage of a process.
    - We had to update the process structure, adding a usage attribute.
  - Add [getusage.c](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/getusage.c) to use getusage call.
- Implement a ["serial killer"](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/proc.c#L588) that kill a process
  - We had to insert code [where the clock interrupt is handled](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/trap.c#L54).

Additionally, we created:
- A program called [victims](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/victims.c), that do a number of forks call to fill Ptable with processes to be killed by Serialkiller.
- A [ps](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/ps.c) program that prints all living processes.
