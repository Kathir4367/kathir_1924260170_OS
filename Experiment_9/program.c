#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main(void){int id;char *p;id=shmget(IPC_PRIVATE,256,IPC_CREAT|0600);if(id<0){perror("shmget");return 1;}p=shmat(id,NULL,0);if(p==(char*)-1){perror("shmat");shmctl(id,IPC_RMID,NULL);return 1;}strcpy(p,"Shared memory IPC demo");printf("Written to shared memory: %s\n",p);if(shmdt(p)<0)perror("shmdt");if(shmctl(id,IPC_RMID,NULL)<0)perror("shmctl");return 0;}