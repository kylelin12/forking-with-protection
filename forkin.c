#include "forkin.h"

// Function to return a struct containing the current time
// Stolen from stackoverflow
struct tm * getTime() {
  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  return timeinfo;
}

int main(){  
  int im_par, status, length, child_fin_id;
  printf("PARENT: I'm starting up\tCurrent time: %s\n", asctime(getTime()));

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

    printf("CHILD: I woke up\tCurrent time: %s\n", asctime(getTime()));

    return t;
  } else { // If the process is a parent
    child_fin_id = wait(&status);
    // *((char *))&status+1)) is a pointer to the memory address located 1 byte after status
    // This places the pointer at the start of "Byte 1" of status.
    printf("PARENT: My child with id %d waited %d seconds\n", child_fin_id, * ((char *)&status+1));
    printf("ALL DONE!\n");
  }
  
  return 0;
}
