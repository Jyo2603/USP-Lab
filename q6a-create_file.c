#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    umask(0022);
    int file = open("demo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    close(file);
    chmod("demo.txt", 0704);
    printf("File 'demo.txt' created with umask, then chmod changed it to 704.\n");
    return 0;
}
