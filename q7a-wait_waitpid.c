#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {  
       printf("Child process\n");
    } else {  
       wait(NULL);  
       printf("Parent process\n");
        waitpid(pid, NULL, 0);  
    }

    return 0;
}
