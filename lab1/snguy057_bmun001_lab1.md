Lab 1 Report
============
Steven Nguyen - snguy057

Brittney Mun - bmun001

## Changes

### proc.h
In proc struct
*Line 52: added int exitStatus //new variable for storing the status's exit status

### proc.c
Changes to exit function:
* Line 229: Changed exit(void) to exit(int status) // Passed in exit status
* Line 226: Added curproc->exitStatus = status; // Saves exit status to the proc struct

Changes to wait function
* Line 228: changed wait(void) to wait(int *status) // variable to save child’s status
* Line 303: added *status = p->exitStatus; // Saves child’s exit status to status

Implemented waitpid with WNOHANG option. Most of the code copied from wait().
* Line 328: changed havekids to pidFound // naming
* Line 328: removed pid, not necessary anymore
* Line 334,338: changed havekids to pidFound
* Line 336: changed to if(p->pid == pid) //checks if the process’s pid is the pid we are waiting on.
* Lines 363-367: Implemented WNOHANG

### sysproc.c
Changes to sys_exit
* Line 20: added status to read in the process's exit status
* Line 21: use argint to get status
* Line 22: changed exit() to exit(status), calls exit function

Changes to sys_wait
* Line 30: added status
* Line 31: use argptr to get pointer of status variable
* Line 32: call wait() to wait(status)
Added sys_waitpid(void)
* Lines 36-46: Implemented here

### defs.h
* Line 107: exit() to exit(int)
* Line 120: wait() to wait(int\*)
* Line 212: added waitpid(int,int\*,int)

### user.h
* Line 6: exit() to exit(int)
* Line 7: wait() to wait(int*)
* Line 8: added int waitpid(int,int\*,int)

### syscall.c
* Line 106: added extern int sys_waitpid(void);
* Line 130: added [SYS_waitpid] sys_waitpid

### syscall.h
* Line 23: added define for waitpid

### usys.S
* Line 32: added syscall for waitpid

