#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeDuplicates (char* str) {
    int alphabet[26] = { 0 };
    int len = strlen(str), current_pos = 0;
    
    for (int i = 0; i < len; i++)
        if (alphabet[str[i]] < 1) alphabet[str[i]]++;

    for (int i = 0; i < len; i++) {
        if (!alphabet[str[i]])
            continue;

        str[current_pos++] = str[i];
        alphabet[str[i]] = 0;
    }

    str[current_pos] = '\0';
}

int main() {
    char str[] = "blabla";
    // removeDuplicates(str);

    printf("Updated str: %s", str);
}

