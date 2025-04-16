#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    umask(0022); 
    FILE *file = fopen("testfile.txt", "w");
    if (file == NULL) {
        perror("File creation failed");
        return 1;
    }
    fclose(file);
    chmod("testfile.txt", 0755); 
    printf("File 'testfile.txt' created and permissions set to 755\n");
    return 0;
}
}
