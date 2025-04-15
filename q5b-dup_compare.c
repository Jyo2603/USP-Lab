#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("dup.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int fd_dup = dup(fd);
    dup2(fd, STDOUT_FILENO);

    write(fd, "Written using fd\n", 17);
    write(fd_dup, "Written using dup(fd)\n", 22);
    printf("Written using dup2(fd, STDOUT_FILENO)\n");

    close(fd);
    close(fd_dup);
}
