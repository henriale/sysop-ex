#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat buf;

    if (argc != 2) {
        printf("Use: %s <filename>\n", argv[0]);
        return (1);
    }

    if (!stat(argv[1],&buf)) {
        printf("%1s", ((buf.st_mode & S_IRUSR) ? "r" : "-"));
        printf("%1s", ((buf.st_mode & S_IWUSR) ? "w" : "-"));
        printf("%1s", ((buf.st_mode & S_IXUSR) ? "x" : "-"));

        printf("%1s", ((buf.st_mode & S_IRGRP) ? "r" : "-"));
        printf("%1s", ((buf.st_mode & S_IWGRP) ? "w" : "-"));
        printf("%1s", ((buf.st_mode & S_IXGRP) ? "x" : "-"));

        printf("%1s", ((buf.st_mode & S_IROTH) ? "r" : "-"));
        printf("%1s", ((buf.st_mode & S_IWOTH) ? "w" : "-"));
        printf("%1s", ((buf.st_mode & S_IXOTH) ? "x" : "-"));

        printf("%7d %s\n", (unsigned int) buf.st_size, argv[1]);
    } else {
        printf("file not found\n");
    }

    return 0;
}