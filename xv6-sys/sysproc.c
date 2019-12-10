#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int numSysCall = 5; //seurattava systeemikutsu
int getcountNUM = -1; //kutsujen lukumäärä

int sys_getcount(void) { //systeemikutsulaskuri
	int x; //reset, 0=n, 1=y
	int y; //syscall jota seurataan, 0 jos edellinen
	
	if(argint(0, &x) < 0) // otetaan ensimmäinen argumentti muuttujaan x ja tarkistetaan että se on jotain järkevää
		return -1;
	if (argint(1, &y) < 0) // otetaan toinen argumentti muuttujaan y ja tarkistetaan että se on jotain järkevää
		return -1;
		
	if (x == 1) { // jos x = 1, resetoidaan laskuri
		getcountNUM = -1;
	}
	if (y > 0 && y < NELEM(syscalls)) { // jos y > 0 ja systeemikutsujen listan rajoissa, asetetaan seurattavan kutsun numero
		numSysCall = y;
	}
	if (getcountNUM == -1) return getcountNUM; //jos laskurin arvo -1, palautetaan se
	else return getcountNUM +1; //muuten palautetaan nykyinen systeemikutsujen lukumäärä (+1 koska aloitetaan numerosta -1)
}

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
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
