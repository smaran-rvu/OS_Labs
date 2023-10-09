#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include <sys/syscall.h>


// Building the executable with the command: gcc -o threadEx2 -D_REENTRANT thread_ex2.c -lpthread 
// Run ps -all to know the PID of prob1, then use that PID in the below command to know

// PIDs of threads. In Linux, same PCB entry is used for holding information about threads too
// Use ps -T -p PID to view thread id: here PID is of parent who created the thread
// SPID alias lwp (light weight process) alias tid (thread id) gives the unique ID of the thread

void *thread1_function(void *arg);
void *thread2_function(void *arg);
void *thread3_function(void *arg);

typedef struct thread_arg_template
{
	char message[50];
	int x;
}thread_arg;

// thread_arg t1, t2, t3;

char message[] = "Introduction to threads !!!";

static int procData = 100;

int main(){

	int stat, stat2, stat3;
	pthread_t thread_id1;
	pthread_t thread_id2;
	pthread_t thread_id3;
	
	int localData = 0;	

	printf("Ububtu \n");

	// *t1.message = "Message to thread1 !!!"; 
	// t1.x = 1;
	// *t2.message = "Message to thread2 !!!";
	// t2.x = 2;
    // *t3.message = "Message to thread3 !!!";
	// t3.x = 3;

    thread_arg t1 = {"Message to thread 1",1};
    thread_arg t2 = {"Message to thread 2",2};
    thread_arg t3 = {"Message to thread 3",3};


	printf("PID of the main process is %d and my PPID %d\n", getpid(), getppid()); 
	
	printf("Going to use pthread_create() POSIX call.\n\n");

	stat = pthread_create(&thread_id1, NULL, thread1_function, (void *)&t1);

	if(stat != 0){ //thread creation failure
	 perror("Error: Thread 1 creation failed\n");
	 exit(EXIT_FAILURE);
	}

	stat2 = pthread_create(&thread_id2, NULL, thread2_function, (void *)&t2);

	if(stat2 != 0){ //thread creation failure
	 perror("Error: Thread 2 creation failed\n");
	 exit(EXIT_FAILURE);
	}
  
	stat3 = pthread_create(&thread_id3, NULL, thread3_function, (void *)&t3);

    if(stat3 != 0){ //thread creation failure
	 perror("Error: Thread 3 creation failed\n");
	 exit(EXIT_FAILURE);
	}

	printf("Main: Thread created successfully\n");
	while(1){
	 sleep(1);
    	 printf("Main: My PID %d\n", (int) getpid());
    	 printf("Main: My TID %d\n", (int) syscall(SYS_gettid));
    	 printf("Main: My procData = %d and localData = %d\n\n",  procData, localData); 
	 procData++;
	 localData++;		
	}

	exit(EXIT_SUCCESS);
  
} // end of main()

void * thread1_function(void *arg){

	int localData1 = 1000;	

	thread_arg *t = (thread_arg *)arg;

	printf("Inside thread: Argument passed to it was %s\n", t->message);
	printf("PID of the thread is %d and my PPID %d\n", getpid(), getppid()); 

    sleep(1);
    while(1){
    	sleep(1);
    	printf("Thread %d: My PID %d\n", t->x, (int) getpid());
    	printf("Thread %d: My TID %d\n", t->x, (int) syscall(SYS_gettid));
    	printf("Thread %d: My procData = %d and localData = %d\n\n", t->x,  procData, localData1);
    	procData++;
	localData1++;		    	
    }
  
} // end of thread_function()

void * thread2_function(void *arg){

	int localData2 = 1000;	

	thread_arg *t = (thread_arg *)arg;

	printf("Inside thread: Argument passed to it was %s\n", t->message);
	printf("PID of the thread is %d and my PPID %d\n", getpid(), getppid()); 

    sleep(1);
    while(1){
    	sleep(1);
    	printf("Thread %d: My PID %d\n", t->x, (int) getpid());
    	printf("Thread %d: My TID %d\n", t->x, (int) syscall(SYS_gettid));
    	printf("Thread %d: My procData = %d and localData = %d\n\n", t->x,  procData, localData2);
    	procData++;
	localData2++;		    	
    }
  
} // end of thread_function()

void * thread3_function(void *arg){

	int localData3 = 1000;	

	thread_arg *t = (thread_arg *)arg;

	printf("Inside thread: Argument passed to it was %s\n", t->message);
	printf("PID of the thread is %d and my PPID %d\n", getpid(), getppid()); 

    sleep(1);
    while(1){
    	sleep(1);
    	printf("Thread %d: My PID %d\n", t->x, (int) getpid());
    	printf("Thread %d: My TID %d\n", t->x, (int) syscall(SYS_gettid));
    	printf("Thread %d: My procData = %d and localData = %d\n\n", t->x,  procData, localData3);
    	procData++;
	localData3++;		    	
    }
  
} // end of thread_function()
