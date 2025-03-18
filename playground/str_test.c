#include <stdio.h>

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void trim_str(char* str) {
    char* replace_pointer = NULL;
   
    // Iterating until \0
    while (*str) {
        if (!replace_pointer && *str == ' ')
            replace_pointer = str; // Pointer to the second space

        if (replace_pointer) {
            if (*str != ' ' || (str[0] == ' ' && str[1] != ' ')) {
                // It's actually a character or the last space
                swap(replace_pointer, str);
                replace_pointer++;
            }
        }

        str++;
    }

    // Close the string
    *replace_pointer = '\0';
}

int main() {
    char str[] = "Hey     A    B C";

    printf("\n\n");
    trim_str(str);
    printf("output string: %s\n", str);
}
