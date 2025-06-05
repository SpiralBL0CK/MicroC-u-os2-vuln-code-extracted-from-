#include <stdio.h>
#include "includes.h"
#include "string.h"

#defome TSK_STKSZ 20248
OS_STK task1_stk[TSK_STKSZ]
OS_STK task2_stk[TSK_STKSZ]

#define TASK1_PRIORITY  1
#define TASK2_PRIORITY  2

void user_input(char *data){
  char name[4];
  strcpy(name,data);
  return;
}

void task1(void *pdata){
  user_input("\x3a\xf0\x4a\x29\xe8\x02\x00\x02");
  while(1){
    printf("Credential Mismatched\n");
    OSTimeDlyHMSM(0,0,3,0);
  }
}

void task2(void *pdata){
  while(1){
    printf("ctf{hardware_hacker}"\n");
    OSTimeDlyHMSM(0,0,3,0);
  }
}

int main()
{
  OSTaskCreateExt(task1,
  NULL,
  (void*)&task1_stk[TSK_STKSZ-1],
  TASK1_PRIORITY,
  TASK1_PRIORITY,
  task1_stk,
  TASK_STACKSIZE,
  NULL,
  0);
  printf("MicroC/OS-II based Buffer Overflow\n");
  OSStart();
  return 0;
}
