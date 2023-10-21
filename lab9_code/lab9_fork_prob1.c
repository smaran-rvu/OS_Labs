#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

// gcc -o exp_lab_1 lab9_fork_prob1.c -lm

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Error: Insufficient/Too many parameters parameters!!!\n");
        printf("Give only one valid integer number as parameter.\n");
        return -1;
    }

    int n = atoi(argv[1]);
    int i = 0, x;

    printf("The number given is: %d\n\n", n);
    printf("After %d forks: (prints message %d times)\n", n, (int)pow(2,(double)n));

    if (n>9 || n<1)
        printf("Number should be between 0 to 10...\n");
    
    else
        for (i; i < n ; i++)
            x = fork();
    
    printf("30FPS > 24FPS... THIS IS THE UNIVERSAL RULE\n");
    
}