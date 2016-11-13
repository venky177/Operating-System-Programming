#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(int argc, char *argv[])
{
    int which = PRIO_PROCESS;
    int old_prio, new_prio, prio;
    id_t who = getpid();

    /* read the nice value from command line */
    if (argc != 2) {
      printf("usage: %s priority\n", argv[0]);
      exit(-1);
    }
    else {
      prio = atoi(argv[1]);
      printf("setting priority to %d!\n", prio);
    }

    /* print the nice value before modifying the same */
    old_prio = getpriority (which, who);
    if (old_prio == -1) {
        printf("getpriority failed!\n");
    }
    else {
        printf("Nice value before change: %d\n", old_prio);
    }

    /* change the nice value of the current process */
    if ( setpriority (which, who, prio) == -1) {
        printf("Failed to change nice value: setpriority failed!\n");
    }
    
    /* check if nice value got changed or not */
    new_prio = getpriority (which, who);
    if (new_prio == -1) {
        printf("getpriority failed!\n");
    }
    else {
        printf("Nice value after change: %d\n", new_prio);
    }

}

