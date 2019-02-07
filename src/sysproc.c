#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  // Lab1: Added to return status
  int status = 0;
  argint(0, &status);
  exit(status);
  return 0;
}

int
sys_wait(void)
{
  // Lab 1: Added to return status
  int* status;
  argptr(0, (char**) &status, sizeof(int*));
  return wait(status);
}

// Lab 1: New syscall that waits on a specific PID
int
sys_waitpid(void)
{
  int pid;
  int* status;
  int options;  
  argint(0, &pid);
  argptr(1, (char**) &status, sizeof(int*));
  argint(2, &options);
  return waitpid(pid, status, options);
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// Lab 2: set the priority of the current process.
int
sys_setpriority(void)
{
  int priority = 0;
  argint(0, &priority);
  setpriority(priority);
  return 0;
}
