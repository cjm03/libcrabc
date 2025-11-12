#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "../include/str.h"

//~ String & Arena 

String StrAlloc(M_Arena* arena, u64 size) {
    String str = {0};
    str.str = (u8*)ArenaAlloc(arena, size + 1);
    str.str[size] = '\0';
    str.size = size;
    return str;
}
String StrCopy(M_Arena* arena, String other) {
    String str = {0};
    str.str = (u8*)ArenaAlloc(arena, other.size + 1);
    str.size = other.size;
    memcpy(str.str, other.str, other.size);
    str.str[other.size] = '\0';
    return str;
}
String StrConcat(M_Arena* arena, String a, String b) {
    String final = {0};
    final.size = a.size + b.size;
    final.str = (u8*)ArenaAlloc(arena, final.size + 1);
    memcpy(final.str, a.str, a.size);
    memcpy(final.str + a.size, b.str, b.size);
    final.str[final.size] = '\0';
    return final;
}
String StrFromFormat(M_Arena* arena, const char* format, ...) {
    va_list args;
    va_start(args, format);
    char buf[8092];
    vsnprintf(buf, 8092, format, args);
    va_end(args);
    u64 size = strlen(buf);
    String s = StrAlloc(arena, size);
    memmove(s.str, buf, size);
    return s;
}
