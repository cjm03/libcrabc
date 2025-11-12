#include <stdio.h>
#include <string.h>
#include "../include/mem.h"

int main(void) {

    M_Arena arena = {0};
    ArenaInitSized(&arena, 2048);

    char* str1 = ArenaAlloc(&arena, 32);
    str1 = "abcdefghijklmnopqrsTUVWXYZ";
    printf("SO: %zu SL: %zu\n", sizeof(str1), strlen(str1));
    printf("str1: %s\n", str1);

    ArenaFree(&arena);

    return 0;
}
