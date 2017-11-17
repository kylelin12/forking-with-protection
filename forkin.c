#include "forkin.h"

int main(){
  int im_par, status, length, child_fin_id;
  printf("PARENT: I'm starting up\n");

  // Creates 1 child
  im_par = fork();

  // If process is parent, fork again to create 2nd child
  if (im_par) {
    im_par = fork();
  }

  // If the process is not a parent
  if (!im_par) {
    printf("CHILD: My PID is %d\n", getpid());

    // srand(time(NULL)); Won't be truly random because the processes are created one after the other
    srand(getpid()); // PID is a unique seed!
    int t = rand() % 16 + 5;
    // printf("CHILD: Sleeping for %d seconds\n", t);
    sleep(t);

    printf("CHILD: I woke up\n");

    return t;
  } else { // If the process is a parent
    child_fin_id = wait(&status);
    printf("PARENT: My child with id %d waited %d seconds\n", child_fin_id, *((char *)&status+1));
    printf("ALL DONE!\n");
  }
  
  return 0;
}
