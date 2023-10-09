#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// gcc -o exp0 -D_REENTRANT lab8_pthread_ex2.c -lpthread 

void *thread1_fn(void *arg);

// This buffer is over written by both the Threads 1 and 2

int main(){
  int val = 100;
  int stat;
  pthread_t thread_id1;
  void *thread1_result;

  printf("Main: Integer passsed %d\n", val);  
  printf("Main: PID of the main process is %d\n", getpid());
  
  stat = pthread_create(&thread_id1, NULL, thread1_fn, (void *)&val);
  
  if(stat != 0){ //thread creation failure
    perror("Main: Error: Thread 1 creation failed\n");
    exit(EXIT_FAILURE);
  }
  
  printf("Main: Thread 1 created successfully\n");
  printf("Main: I am going to sleep for 10 seconds ...\n");
  printf("Main: Allowing my Thread 1 to run for a while.\n");
  sleep(10);

  printf("Main: I am going to run forever...\n");
  while(1)
  {
    sleep(10);
    printf("Main: I am still alive\n");
    printf("Main: The current value of val is %d\n", val);
  }

  // printf("Main: I am going to call pthread_exit(), now, observe what happens to my thread\n");
  // pthread_exit(EXIT_SUCCESS);

}

void * thread1_fn(void *arg){
  int * cnt = (int *) arg;

  printf("Thread1: I am created.\n");
  printf("Thread1: Integer passsed from parent thread is '%d\n", *cnt);
  printf("Thread1: I am going to sleep for 2 seconds now...\n");
  sleep(2);
  
  printf("Thread1: I plan to run forever\n");
  while(1) {
    sleep(2);
    printf("Thread1: %d: I am still alive and incrementing\n", *cnt);
    *cnt += 1;
  }
    // printf("Thread1: I am going to call pthread_exit(), now, observe what happens to my thread\n");
    // pthread_exit(EXIT_SUCCESS);
  
} // end of thread1_function()
