#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    fork();
    fork();
    fork();
    printf("Hello World\n");

    return 0;
}