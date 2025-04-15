#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int file = open("test.txt", O_RDONLY);
    char buf[21];

    read(file, buf, 20);
    buf[20] = '\0';
    printf("First 20 chars     : %s\n", buf);

    lseek(file, 10, SEEK_SET);
    read(file, buf, 20);
    buf[20] = '\0';
    printf("From 10th byte     : %s\n", buf);

    lseek(file, 10, SEEK_CUR);
    read(file, buf, 20);
    buf[20] = '\0';
    printf("10 bytes ahead     : %s\n", buf);

    struct stat st;
    stat("test.txt", &st);
    printf("File size          : %ld bytes\n", st.st_size);

    close(file);
    return 0;
}
