#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *ep;

    if (argc != 2) {
        printf("Use: %s <directory>\n", argv[0]);
        return 1;
    }

    dp = opendir(argv[1]);
    if (dp == NULL) {
        printf("Couldn't open the directory %s", argv[1]);
        return 1;
    }

    while (ep = readdir(dp)) {
        switch (ep->d_type) {
            case DT_UNKOWN:
                printf("?");
                break;
            case DT_REG:
                printf("f");
                break;
            case DT_DIR:
                printf("f");
                break;
            default:
                printf("o");
                break;
        }
        printf(" %20s\n", ep->d_name);
    }
    closedir(dp);

    return 0;
}