#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// gcc -o exp0 -D_REENTRANT lab8_pthread_ex3.c -lpthread 

void *thread1_fn(void *arg);

typedef struct lab8_pthread_ex3
{
    char name[50];
    char USN[13];
    char branch[20];
    
}user_data;

user_data details;

int val = 100;

int main(){

  int stat;
  pthread_t thread_id1;
  void *thread1_result;

  strcpy(details.name, "Smaran R Bharadwaj");
  strcpy(details.branch, "BTech");
  strcpy(details.USN, "1RVU22CSE157");

  printf("Main: PID of the main process is %d\n", getpid());
  
  stat = pthread_create(&thread_id1, NULL, thread1_fn, (void *)&details);
  
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
    // printf("Main: The current value of val is %d\n", val);
  }

  // printf("Main: I am going to call pthread_exit(), now, observe what happens to my thread\n");
  // pthread_exit(EXIT_SUCCESS);

}

void * thread1_fn(void *arg){
  user_data * details = (user_data *) arg;

  printf("Thread1: I am created.\n");
  printf("Thread1: Name of student is %s\n", details->name);
  printf("Thread1: Branch of student is %s\n", details->branch);
  printf("Thread1: USN of student is %s\n", details->USN);
  printf("Thread1: I am going to sleep for 2 seconds now...\n");
  sleep(2);
  
  printf("Thread1: I plan to run forever\n");
  while(1) {
    sleep(2);
    printf("Thread1: Name of student is %s\n", details->name);
    printf("Thread1: Branch of student is %s\n", details->branch);
    printf("Thread1: USN of student is %s\n", details->USN);
    printf("Thread1: I am going to sleep for 2 seconds now...\n");
  }
    // printf("Thread1: I am going to call pthread_exit(), now, observe what happens to my thread\n");
    // pthread_exit(EXIT_SUCCESS);
  
} // end of thread1_function()
