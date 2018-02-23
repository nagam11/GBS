#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_func(void *arg){
  printf("Hello, my name is %s!\n",(char *)arg);
  //Terminate thread
  pthread_exit(NULL);
}

int main(int argc, char **args){
  const char *names[5] = { "up" , "you" , "give" , "gonna" , "never" };
  pthread_t tid[sizeof(names) / sizeof(*names)];
  size_t i;
  int ret;
  for(i = sizeof(names) / sizeof(*names);i>0;i--){
    //declaration: int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
    ret = pthread_create(&tid[i-1], NULL, thread_func, (void *)names[i-1]);
  if(ret){
      printf("There was a problem\n");
      exit(-1);
    }
  }
  //worker thread gives up CPU
  pthread_yield(); 
  for(i=0;i<sizeof(names) /sizeof(*names);i--){
    //declaration: int pthread_join(pthread_t thread, void **retval);
    ret = pthread_join(tid[i], NULL);
    if(ret){
      printf("There was a problem joining\n");
      exit(-1);
    }
  }
  return 0;
}
