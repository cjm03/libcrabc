// str.c - Custom String Library

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/str.h"
#include "../include/stdstr.h"

String* CreateString(char* string) {
    String* s = malloc(sizeof(String));
    if (s == NULL) {
        fprintf(stderr, "malloc: error allocating String\n");
        return NULL;
    }
    size_t len = strlen(string);
    s->size = len;
    s->str = malloc(len + 1);
    if (s->str == NULL) {
        fprintf(stderr, "malloc: error allocating s->str\n");
        free(s);
        return NULL;
    }
    memcpy(s->str, string, len);
    s->str[len] = '\0';
    return s;
}

String* CreateSlicedString(String* s, size_t start_idx, size_t end_idx) {
    String* new = CreateString(s->str);
    SliceString(new, start_idx, end_idx);
    return new;
}

void SliceString(String* s, size_t start_idx, size_t end_idx) {
    size_t newsize = end_idx - start_idx + 1;
    char* full = Strndup(s->str, s->size);
    ClearString(s);
    s->str = realloc(s->str, newsize + 1);
    for (size_t i = 0; i < newsize; i++) {
        s->str[i] = full[i + start_idx];
    }
    s->size = newsize;
    free(full);
}

String* DuplicateString(String* s) {
    String* new = CreateString(s->str);
    return new;
}

char* GetStringData(String* s) {
    char* temp = Strndup(s->str, s->size);
    return temp;
}

void PrintString(String* s) {
    printf("String: {%s}\nSize: {%zu}\n", s->str, s->size);
}

size_t GetStringSize(String* s) {
    return s->size;
}

void ClearString(String* s) {
    if (s == NULL) {
        fprintf(stderr, "Cannot free empty string structure\n");
        return;
    }
    if (s->str == NULL) {
        fprintf(stderr, "Cannot free empty string!\n");
        return;
    }
    memset(s->str, 0, s->size);
}

void DeleteString(String* s) {
    if (s == NULL) {
        fprintf(stderr, "Cannot free empty string structure\n");
        return;
    }
    if (s->str == NULL) {
        fprintf(stderr, "Cannot free empty string!\n");
        return;
    }
    free(s->str);
    free(s);
}
