// str.h
//
// Headerfile for str.c, a custom library for simpler management, control, and customization
// of strings in C.
//
// Charlie Moye
// 11-12-2025

#ifndef STR_H
#define STR_H

#include <stddef.h>
#include "../include/mem.h"

typedef struct String {
    char* str;              // The string itself
    size_t size;            // The length of the string, minus the null terminator.
} String;

/////////////////////////////////
//
// String Functions Using Malloc

/**
 *  Allocate memory and create a new String*.
 *  char* string: The string to allocate for and store.
 *  Return: Pointer to the String structure containing the string
 */
String* CreateString(char* string);

/**
 *  Slice a string and store it as a new string.
 *  String* s: The original string structure containing the string to be sliced.
 *  size_t start_idx: The starting index to slice. (Will be included in new string)
 *  size_t end_idx: The ending index to slice. (Will be included in new string)
 *  Return: Pointer to the new String structure containing the sliced string.
 */
String* CreateSlicedString(String* s, size_t start_idx, size_t end_idx);

/**
 *  Slice a string in place.
 *  String* s: The string structure to be sliced.
 *  size_t start_idx: The starting index to slice. (Will be included in sliced string)
 *  size_t end_idx: The ending index to slice. (Will be included in sliced string)
 *  Return: no return.
 */
void SliceString(String* s, size_t start_idx, size_t end_idx);

/**
 *  Create a duplicate of a string.
 *  String* s: The string structure to be duplicated.
 *  Return: Pointer to the duplicated string structure.
 */
String* DuplicateString(String* s);

/**
 *  Get the string stored in the structure.
 *  String* s: The string structure of the desired string.
 *  Return: An allocated char pointer storing a new copy of the string. Must be freed!
 */
char* GetStringData(String* s);

/**
 *  Print the string in the struct.
 *  String* s: The structure containing the string to be printed.
 *  Return: no return val
 */
void PrintString(String* s);

/**
 *  Get the string size from the struct.
 *  String* s: The structure containing the desired string's size.
 *  Return: size_t integer representing the length of the string
 */
size_t GetStringSize(String* s);

/**
 *  Erase the contents of an allocated string.
 *  String* s: The structure containing the string to be cleared.
 *  Return: no return val.
 */
void ClearString(String* s);

/**
 *  Release a string's memory.
 *  String* s: The structure to be freed.
 *  Return: no return val.
 */
void DeleteString(String* s);


//////////////////////////////////
//
// String Functions Using Arenas

String M_CreateString(M_Arena* arena, char* string);
String M_CreateSlicedString(M_Arena* arena, String* s, size_t start_idx, size_t end_idx);
String M_PrintString();






#endif // STR_H
