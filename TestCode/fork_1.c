#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_COUNT 10
#define BUF_SIZE 100

void ChildProcess()
{
    for(int i = 1; i <= MAX_COUNT; i++)
        printf("This line is from Child pid. Value = %d\n", i);
    printf("****Child process is done***\n");

}

void ParentProcess()
{
    for(int i = 1; i <= MAX_COUNT; i++)
        printf("This line is from Parent pid. Value = %d\n", i);
    printf("****PARENT process is done***\n");

}


int main(void)
{
    pid_t pid;

    pid = fork();

    if(pid == 0)
        ChildProcess();
    else
        ParentProcess();

    return 0;
}