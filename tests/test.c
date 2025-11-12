#include <stdio.h>
#include <string.h>
#include "../include/mem.h"
#include "../include/str.h"

int main(void) {

    M_Arena arena = {0};
    ArenaInitSized(&arena, 2048);

    char* str1 = ArenaAlloc(&arena, 32);
    str1 = "abcdefghijklmnopqrsTUVWXYZ";
    String s = StrLit(str1);
    String t = StrCopy(&arena, s);
    printf("SO: %zu SL: %zu\n", sizeof(str1), strlen(str1));
    printf("s: %s\n", s.str);
    printf("str1: %s\n", str1);
    printf("t: %s\n", t.str);

    ArenaFree(&arena);

    return 0;
}
