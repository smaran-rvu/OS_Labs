#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
# include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("Find the sum of numbers entered by the user!!!\n");

    if(argc != 2){
        printf("Error: Insufficient/Too many parameters parameters!!!\n");
        printf("Give only one valid integer number as parameter.\n");
        return -1;
    }

    int n = argv[1];

    printf("The number given is: %d\n", n);

    printf("");
}