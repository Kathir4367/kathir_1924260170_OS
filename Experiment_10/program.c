#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct msg {long type; char text[100];};
int main(void){int id;struct msg m;id=msgget(IPC_PRIVATE,IPC_CREAT|0600);if(id<0){perror("msgget");return 1;}m.type=1;strcpy(m.text,"Message queue IPC demo");if(msgsnd(id,&m,sizeof(m.text),0)<0){perror("msgsnd");msgctl(id,IPC_RMID,NULL);return 1;}if(msgrcv(id,&m,sizeof(m.text),1,0)<0){perror("msgrcv");msgctl(id,IPC_RMID,NULL);return 1;}printf("Received message: %s\n",m.text);msgctl(id,IPC_RMID,NULL);return 0;}