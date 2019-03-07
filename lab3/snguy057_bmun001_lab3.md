Lab 3 Report
============
Steven Nguyen - snguy057

Brittney Mun - bmun001

## Changes
### proc.h
* Line 52: Created uint pages

![lab3_proch](lab3_proch.PNG)

### memlayout.h
Defined top of stack address
* Line 18: Defined memory address for top of stack.

![lab3_memlayout](lab3_memlayout.PNG)

### proc.c
Copied pages to child processes
* Line 204: Copied pages to child process as well.

![lab3_procc](lab3_procc.PNG)

### syscall.c
Implemented Lab 3 by replacing cur-proc->sz with TOPSTACK throughout the file.
* Line 24, 42, 45, 74: Use TOPSTACK instead of curproc->sz.

![lab3_syscall1](lab3_syscall1.PNG)

![lab3_syscall2](lab3_syscall2.PNG)

![lab3_syscall3](lab3_syscall3.PNG)

### vm.c
Copies over information into virtual memory.
* Lines 340 - 352: Loop in order to copy information onto the new stack.

![lab3_vm](lab3_vm.PNG)

### exec.c
Allocates all pages starting from the top of the stack. Replaces all sz with TOPSTACK.
* Line 65, 67: Replace sz with TOPSTACK.
* Line 102: Set number of pages to 1.

![lab3_exec](lab3_exec.PNG)

### trap.c
Implemeneted page faults
* Lines 81 - 93: Implemented page faults.

![lab3_trap](lab3_trap.PNG)

## Extra Credit
We were unable to implement a stack that grows into the heap because this would cause the stack to overlap the heap. As a result, the stack would overwrite information contained within the heap. The heap is allocated within vm.c and shown below. Within the I/O space is the heap. By growing the stack towards the heap, we effectively reach outside of the size limitations of the stack and cause an overflow, which would break the kernel and trigger an overflow error.

![lab3_extra](lab3_extra.PNG)
