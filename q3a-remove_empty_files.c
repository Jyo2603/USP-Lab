#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    DIR *d = opendir(".");
    struct dirent *e;
    struct stat s;

    while ((e = readdir(d))) {
        stat(e->d_name, &s);
        if (S_ISREG(s.st_mode) && s.st_size == 0) {
            printf("Removing empty file: %s\n", e->d_name);
            remove(e->d_name);
        }
    }

    closedir(d);
}
