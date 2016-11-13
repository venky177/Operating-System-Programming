#include<stdio.h>
#include<fcntl.h>

#define MAX_CHARS 10000

main()
{
    int fd; 
    char line[MAX_CHARS];
    ssize_t n;

    fd = open("/proc/cpuinfo", O_RDONLY);
    if (fd == -1) {
        printf("open failed\n");
    }
    else {
        n = read (fd, line, MAX_CHARS);
        if (n == -1) {
            printf("read failed\n");
        }
        else {
            printf("%s\n", line);
        }
    }
}

