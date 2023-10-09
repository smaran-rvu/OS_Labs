#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// gcc -o exp5 -D_REENTRANT lab8_assign7_prob2.c -lpthread 

void *thread1_fn(void *arg);

int main()
{
  int stat;
  int arr[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
  pthread_t thread_id[10];
  void *thread_result[10];
  
  printf("Main: PID of the main process is %d\n", getpid());
  
  for(int i = 0 ; i < 10 ; i++)
  {
    stat = pthread_create(&thread_id[i], NULL, thread1_fn, (void *)&arr[i]);
    
    if(stat != 0){ //thread creation failure
        perror("Main: Error: Thread creation failed\n");
        exit(EXIT_FAILURE);
    }
    else
        printf("Main: Thread %d created\n", i+1);

  }
  
  for(int i = 1 ; i < 10 ; i++)
  {
    printf("Main: Going to wait for the Thread%d to finish ...\n",i+1);
    stat = pthread_join(thread_id[i], &thread_result[i]);
  
    if(stat != 0){ // thread join has failed
        perror("Main: Thread1 join failed\n");
        exit(EXIT_FAILURE);    
    }
  }

  printf("Main: I am going to call pthread_exit()\n");
  pthread_exit(EXIT_SUCCESS);

}

void * thread1_fn(void *arg){
  int val = *(int *) arg;
  
  val = val/100;
  printf("  Thread%d: I am created.\n", val);
  printf("  Thread%d: The value passed to me is %d.\n", val, val*100);
  printf("  Thread%d: I am going to sleep for %d second(s) now...\n\n", val, val);
  sleep(val);
  
  // printf("Thread1: I plan to run forever\n");
  // while(1) {
  //   sleep(2);
  //   
  //   int sum = 0;
  //   
  //   printf("Thread1: I am still alive and the average is %d\n", sum);
  // }
  printf("  Thread%d: I am going to call pthread_exit()\n", val);
  pthread_exit(EXIT_SUCCESS);
  
} // end of thread1_function()