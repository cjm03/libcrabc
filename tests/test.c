#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../allhead.h"

int main(void)
{
    String* first = CreateString("What does the fox say?");
    String* second = CreateString("abcdefghijklmnopqrstuvwxyz0123456789");

    char* first_local = GetStringData(first);
    char* second_local = GetStringData(second);

    PrintString(first);
    PrintString(second);
    printf("first_local: %s\nSize: %zu\n", first_local, strlen(first_local));
    printf("second_local: %s\nSize: %zu\n", second_local, strlen(second_local));

    free(first_local);
    free(second_local);

    SliceString(first, 5, 12);
    String* second_dns = CreateSlicedString(second, 24, 32);

    PrintString(first);
    PrintString(second);
    PrintString(second_dns); 

    DeleteString(first);
    DeleteString(second);
    DeleteString(second_dns); 
}
