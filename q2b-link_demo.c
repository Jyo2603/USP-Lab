#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

void show(char *f) {
    struct stat s;
    stat(f, &s);
    printf( (S_ISLNK(s.st_mode)) ? "l" : "-" );
    printf( (s.st_mode & S_IRUSR) ? "r" : "-" );
    printf( (s.st_mode & S_IWUSR) ? "w" : "-" );
    printf( (s.st_mode & S_IXUSR) ? "x" : "-" );
    printf( (s.st_mode & S_IRGRP) ? "r" : "-" );
    printf( (s.st_mode & S_IWGRP) ? "w" : "-" );
    printf( (s.st_mode & S_IXGRP) ? "x" : "-" );
    printf( (s.st_mode & S_IROTH) ? "r" : "-" );
    printf( (s.st_mode & S_IWOTH) ? "w" : "-" );
    printf( (s.st_mode & S_IXOTH) ? "x" : "-" );
    printf(" %ld %lld %s", s.st_nlink, (long long)s.st_size, f);
    if (S_ISLNK(s.st_mode)) printf(" -> original.txt");
    printf("\n");
}

int main() {
    link("original.txt", "hardlink.txt");
    symlink("original.txt", "softlink.txt");
    show("original.txt");
    show("hardlink.txt");
    show("softlink.txt");
    return 0;
}
