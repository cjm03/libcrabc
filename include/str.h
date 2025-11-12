#ifndef STR_H
#define STR_H

#include <stddef.h>

typedef struct String {
    char* str;
    size_t size;
} String;

String* CreateString(char* string);
String* CreateSlicedString(String* s, size_t start_idx, size_t end_idx);
void SliceString(String* s, size_t start_idx, size_t end_idx);
String* DuplicateString(String* s);
char* GetStringData(String* s);
void PrintString(String* s);
size_t GetStringSize(String* s);
void ClearString(String* s);
void DeleteString(String* s);

#endif // STR_H
