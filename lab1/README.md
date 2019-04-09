# Laboratory 1 - System calls and interrupts
In this lab, we practice the implementation of system calls and interrupts. The purposes of it is to understand the system call execution flow and its implementation, how a process is scheduled to run and finally how interrupts works. 

The tasks were:
- Print each system call when invoked.
- Implement inicially two system calls
  - Add system call [getpriority](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/proc.c#L538): to retrieve the priority of a process.
    - We had to update the process structure, adding a prio attribute.
  - Add system call [setpriority](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/proc.c#L553): to update the priority of a process.
  - Add [nice.c](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/nice.c) to use those system calls.
- Implement a system call that returns how many times a process run 
  - Add system call [getusage](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/proc.c#L570): to retrieve the usage of a process.
    - We had to update the process structure, adding a usage attribute.
  - Add [getusage.c](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/getusage.c) to use getusage call.
- Implement a ["serial killer"](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/proc.c#L586) that kill a process
  - We had to [insert code](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/trap.c#L54) where the [clock interrupt is handled](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/trap.c#L50).
  
Additionally, we created:
- A program called [victims](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/victims.c), that do a number of fork calls to fill Ptable with processes to be killed by Serialkiller.
- A [ps](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/ps.c) program that prints all living processes.

## Syscall execution flow
To easily understand the implementation of an xv6 syscall, we'll explain why each file used were modified and what is its role. Let's begin our tour explaining our program that invokes ps command and walks through each file doing the same.
### ps.c & user.h
The [ps.c](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/ps.c) is a simple C program that only exists to [call the ps syscall](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/ps.c#L7). It [imports that code from user.h](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/ps.c#L2). The [user.h](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/user.h) is a file where the contract of functions that may be used for programers resides. We can see the ps function [here](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/user.h#L29)
### usys.S & syscall.h
The main content of [usys.S](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/usys.S) is a macro, that provide a polimorfic way to call syscalls. The generic define of a syscall resides [here](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/usys.S#L4). As we can see, it creates a string based on the syscall name and get its value from [syscall.h](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/syscall.h#L27). The value retrieved is saved at the %eax register to future usage using the movl command. After that use the int command that calls a interruption of T_SYSCALL type that leads us to trap.c.   
### trap.c
At [trap.c](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/trap.c) is where interrupts are treated. For the proporse of that laboratory, we want to comment two lines: 

- [Where the syscall function is called](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/trap.c#L43): this line calls the function in syscall.c that executes chained calls until run system call source code (we explain better next). 
- [The case where clock interruptions treated](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/trap.c#L50): the case that indentifies if a given interruption is a clock interruption (it was used to implement the serial killer feature).

### syscall.c
The [syscall.c](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/syscall.c) remain the last treatment until execute the system call code. Ok, let's start looking at [syscall.c syscall function](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/syscall.c#L168). As we have already said, it is the function used in trap.c to invoked a system call. That function read the [value in %eax](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/syscall.c#L173) to know what system call execute and then it [retrieves and save the result](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/syscall.c#L175) of the [nonparametric function](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/syscall.c#L111) implemented in [sysproc.c (we choose ps as example)](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/sysproc.c#L124)

### sysproc.c & proc.c
At [sysproc.c](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/sysproc.c) we have nonparametric implementation of functions that finally invokes functions which executes the system call source code. These final functions are implemented in 
[proc.c](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/proc.c) and here we can see [ps system call source code](https://github.com/dfquaresma/prso-xv6/blob/master/lab1/proc.c#L608). 
