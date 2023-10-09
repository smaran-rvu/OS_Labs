#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// gcc -o exp4 -D_REENTRANT lab8_assign7_prob1.c -lpthread 

void *thread1_fn(void *arg);

typedef struct lab8_assign7_prob1
{
    int len;
    int arr[100];
}user_array;

user_array arr1;

int arr[] = {10,20,30,40,50,60,70,80};

int main(){

  arr1.len = 8;
  for(int i = 0 ; i < arr1.len ; i++)
  {
    arr1.arr[i] = arr[i];
  }

  int stat;
  pthread_t thread_id1;
  void *thread1_result;
  
  printf("Main: PID of the main process is %d\n", getpid());
  
  stat = pthread_create(&thread_id1, NULL, thread1_fn, (void *)&arr1);
  
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
  }

  // printf("Main: I am going to call pthread_exit(), now, observe what happens to my thread\n");
  // pthread_exit(EXIT_SUCCESS);

}

void * thread1_fn(void *arg){
  user_array * arr1 = (user_array *) arg;

  

  printf("Thread1: I am created.\n");
  printf("Thread1: I am going to sleep for 2 seconds now...\n");
  sleep(2);
  
  printf("Thread1: I plan to run forever\n");
  while(1) {
    sleep(2);

    int sum = 0;
    for(int i = 0; i < arr1->len; i++)
    {
        sum+=arr1->arr[i];
    }
    sum = sum/arr1->len;

    printf("Thread1: I am still alive and the average is %d\n", sum);
  }
    // printf("Thread1: I am going to call pthread_exit(), now, observe what happens to my thread\n");
    // pthread_exit(EXIT_SUCCESS);
  
} // end of thread1_function()
