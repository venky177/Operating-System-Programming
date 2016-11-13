#include <stdio.h>
//#include <sys/types.h>
//#include <unistd.h>
//#include <stdlib.h>

main()
{
    int a;
    a=fork ();
    if (a==0) {
    printf ("this is the child process, with processid %d\n",getpid());

     printf ("this is the child process, with groupid %d\n",getgid());

    printf ("this is the child process, with parentprocessid %d\n",getppid());
    }
    else {
sleep(3);
    printf ("this is the parent process, with processid %d\n",getpid());

    printf ("this is the parent process, with groupid %d\n",getgid());
    }
}
