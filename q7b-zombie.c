#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process exiting...\n");
        _exit(0);
    } else {
        printf("Parent process sleeping for 10 seconds...\n");
        sleep(10);
        wait(NULL);
        printf("Parent process finished.\n");
    }

    return 0;
}
