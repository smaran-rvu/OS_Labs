#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// gcc -o exp0 -D_REENTRANT lab8_pthread_ex1.c -lpthread 

void *thread1_fn(void *arg);

// This buffer is over written by both the Threads 1 and 2
char msg[] = "Hello, OS_SS Lab8 class ... pthread_create";

int main(){

  int stat;
  pthread_t thread_id1;
  void *thread1_result;

  printf("Main: %s\n", msg);  
  printf("Main: PID of the main process is %d\n", getpid());
  
  stat = pthread_create(&thread_id1, NULL, thread1_fn, (void *)msg);
  
  if(stat != 0){ //thread creation failure
    perror("Main: Error: Thread 1 creation failed\n");
    exit(EXIT_FAILURE);
  }
  
  printf("Main: Thread 1 created successfully\n");
  printf("Main: I am going to sleep for 10 seconds ...\n");
  printf("Main: Allowing my Thread 1 to run for a while.\n");
  sleep(10);

  printf("Main: I am going to call pthread_exit(), now, observe what happens to my thread\n");
  pthread_exit(EXIT_SUCCESS);

}

void * thread1_fn(void *arg){
  int cnt = 1;

  printf("Thread1: I am created.\n");
  printf("Thread1: Message passsed from parent thread is '%s'\n", (char *)arg);
  printf("Thread1: I am going to sleep for 2 seconds now...\n");
  sleep(2);
  
//   printf("Thread1: I plan to run forever\n");
  while(1) {
    sleep(2);
    printf("Thread1: %d: I am still alive\n", cnt);
    cnt++;
  }
    // printf("Thread1: I am going to call pthread_exit(), now, observe what happens to my thread\n");
    // pthread_exit(EXIT_SUCCESS);
  
} // end of thread1_function()
