#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// gcc -o exp_lab_1 lab9_fork_prob2.c

int main()
{
    int n;

    printf("Parent: Forking now...\n");
    n = fork();

    if (n)
    {        
        printf("Parent: You know.. The USB-C Apple pencil is... Meh :/\n");
        printf("Parent: Exiting process, thank you for reading me!! :)\n\n");
    }

    else
    {
        printf("Child: I am going to sleep for 10 seconds\n");
        sleep(10);
        printf("Child: I am now awake... I wanna sleep more (T-T)\n");

        printf("Child: Forking now... again\n\n");
        n = fork();

        if (n)
            printf("Child-Parent: I'm gonna exit, byee!!\n");
        else
            printf("Child-Child: See ya later! Press enter to exit\n");
    }
    return 0;
}