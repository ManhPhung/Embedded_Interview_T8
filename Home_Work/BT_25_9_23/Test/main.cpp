#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include<string.h>

int main() {
    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL) {
        perror("Lỗi mở file");
        exit(EXIT_FAILURE);
    }
    // ...
    fclose(file);
    return 0;
}
