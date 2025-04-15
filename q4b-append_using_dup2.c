#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("file.txt", O_RDWR);
    char buf[50];
    int n = read(fd, buf, 50);
    lseek(fd, 0, SEEK_END);
    dup2(fd, STDOUT_FILENO);
    write(STDOUT_FILENO, buf, n);
    close(fd);
    return 0;
}
