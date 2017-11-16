#include "forkin.h"

int main(){
  printf("PARENT: I'm starting up\n");

  if (!fork()){
    printf("CHILD: My PID is %d\n", getpid());

    srand(time(NULL));
    int t = rand() % 15 + 5;
    //printf("CHILD: Sleeping for %d seconds\n", t);
    sleep(t);

    printf("CHILD: I woke up\n");

    return t;
  }
  
  return 0;
}
