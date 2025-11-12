#include <stdio.h>
#include <string.h>
#include "../include/mem.h"

typedef struct Vec3 {
    float x, y, z;
} Vec3;

int main(void) {

    M_Arena arena;
    ArenaInitSized(&arena, 1024);

    Vec3* vec = ArenaAlloc(&arena, sizeof(Vec3));
    vec->x = 1.0f; 
    vec->y = 2.0f; 
    vec->z = 3.0f;
    printf("vec = {%.2f, %.2f, %.2f}\n", vec->x, vec->y, vec->z);

    int* arr = ArenaAlloc(&arena, sizeof(int) * 100);
    for (int i = 0; i < 100; ++i) {
        arr[i] = i * i;
    }
    printf("arr[10] = %d, arr[99] = %d\n", arr[10], arr[99]);

    size_t mark = ArenaGetMarker(&arena);
    char* temp = ArenaAlloc(&arena, sizeof(char) * 256);
    strcpy(temp, "temporary buffer");
    printf("temp before restore: %s\n", temp);

    ArenaRestoreToMarker(&arena, mark);

    char* temp2 = ArenaAlloc(&arena, sizeof(char) * 32);
    strcpy(temp2, "reused");
    printf("temp after restore & reuse: %s\n", temp2);

    ArenaClear(&arena);

    Vec3* vecn = ArenaAlloc(&arena, sizeof(Vec3));
    vecn->x = 9; 
    vecn->y = 8; 
    vecn->z = 7;
    printf("vecn = {%.0f, %.0f, %.0f}\n", vecn->x, vecn->y, vecn->z);
    

    ArenaFree(&arena);
    return 0;
}
