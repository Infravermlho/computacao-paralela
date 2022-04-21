#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>   

int main()
{
    pid_t pid;
    int ShmID; 
    int size = 1024;
    int *value;
    
    ShmID = shmget(IPC_PRIVATE, size, IPC_CREAT | 0666);
    if(ShmID < 0){
      printf("Erro no shmget\n");
      exit(1);
    }
    
    value = (int*) shmat(ShmID, NULL, 0);
    *value = 1;
    printf("Valor inicial: %i\n", *value);
    pid = fork();
    if (pid == 0)
    {     
        *value += 2; 
        printf("Valor apos a soma: %i\n",*value);    
    }
    else
    {
        wait(-1);     
        *value *= 4;
        printf("Valor apos a multiplicacao: %i\n",*value);    
    }
    
    exit(0);
}
