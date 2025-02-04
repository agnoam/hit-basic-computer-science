#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "black_box.c"

void print_key(int* arr, int n, int key);
int* get_unique_a(int* a, int n, int* b, int m, int* c_size);
int* get_elements_of_ab(int* a, int n, int* b, int m, int* c_size);
int is_anagram(char* str1, char* str2);
int get_smallest_num_than_k(int* arr, int n, int k);

int main() {
    printf("\n\n");

    // Q1
    int arr[] = { 2, 13, 3, 9, 1 };
    printf("Should be: 2 3 9\n");
    print_key(arr, sizeof(arr) / sizeof(arr[0]), 3);
    printf("\n");

    // Q2.a
    int a[] = { 5, 7, 10, 15, 2, 4 };
    int b[] = { 1, 5, 2, 24, 56, 70, 71 };
    int c_size = 0;
    int *c = get_unique_a(a, sizeof(a) / sizeof(a[0]), b, sizeof(b) / sizeof(b[0]), &c_size);
    printf("Output array should be: 7 10 15 4:\n");
    print_array(c, c_size);

    // Q2.b
    int _a[] = { 2,4,5,7,10,15 };
    int _b[] = { 1,2,4,7,9,10,70,71 };
    c = get_elements_of_ab(_a, sizeof(_a) / sizeof(_a[0]), _b, sizeof(_b) / sizeof(_b[0]), &c_size);
    printf("Output array should be: 2 4 7 10:\n");
    print_array(c, c_size);

    // Q3
    char str1[] = "Tom Marvolo Riddle";
    char str2[] = "I Am Lord Voldemort";
    printf("Should be 1: %d\n", is_anagram(str1, str2));

    char str3[] = "anagraM";
    char str4[] = "Margarina";
    printf("Should be 0: %d\n", is_anagram(str3, str4));

    // Q4
    int arr_f[] = { 2,3,3,3,5,7,7,10 };
    printf("Should be 5: %d\n", get_smallest_num_than_k(arr_f, sizeof(arr_f) / sizeof(arr_f[0]), 3));
    printf("Should be -1: %d\n", get_smallest_num_than_k(arr_f, sizeof(arr_f) / sizeof(arr_f[0]), 10));
}

void print_key(int* arr, int n, int key) {
    if (!n)
        return;
    
    if (n == 1 && !(arr[0] % key))
        printf("%d ", arr[0]);
    else if (!(arr[0] % key) || !((arr[0] + arr[1]) % key))
        printf("%d ", arr[0]);
    
    return print_key(arr+1, n-1, key);
}

int* get_unique_a(int* a, int n, int* b, int m, int* c_size) {
    int i, j, found, c_index = 0;
    int* c = malloc((n + m) * sizeof(int));
    int* new_c = NULL;

    if (!c)
        return NULL;

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                found = 1;
                break;
            }
        }

        if (!found) c[c_index++] = a[i];
    }

    new_c = realloc(c, c_index * sizeof(int));
    *c_size = c_index;
    if (!new_c) {
        free(c);
        *c_size = -1;
    }

    return new_c;
}

int* get_elements_of_ab(int* a, int n, int* b, int m, int* c_size) {
    int a_index = 0, b_index = 0, c_index = 0;
    int* c = malloc(n >= m ? n : m * sizeof(int));
    int* new_c = NULL;
    if (!c)
        return NULL;

    while (a_index < n && b_index < m) {
        if (a[a_index] == b[b_index]) {
            c[c_index++] = a[a_index];
            a_index++;
            b_index++;
        } else if (a[a_index] > b[b_index]) {
            b_index++;
        } else {
            a_index++;
        }
    }

    new_c = realloc(c, (c_index) * sizeof(int));
    *c_size = c_index;
    if (!new_c) {
        free(c);
        *c_size = -1;
    }

    return new_c;
}

int char_pos(char c) {
    if (c - 'A' >= 0 && c - 'A' <= 25)
        return c - 'A';
    if (c - 'a' <= 25 && c - 'a' >= 0)
        return c - 'a';
}

int is_anagram(char* str1, char* str2) {
    int i, len1 = strlen(str1), len2 = strlen(str2);
    int counter_1[26] = { 0 };
    int counter_2[26] = { 0 };

    for (i = 0; i < len1; i++)
        str1[i] != ' ' && counter_1[char_pos(str1[i])]++;

    for (i = 0; i < len2; i++)
        str2[i] != ' ' && counter_2[char_pos(str2[i])]++;

    for (i = 0; i < 26; i++) {
        if (counter_1[i] != counter_2[i])
            return 0;
    }

    return 1; 
}

int get_smallest_num_than_k(int* arr, int n, int k) {
    int left = 0, right = n - 1, mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (left == right && k - arr[mid] < 0)
            return arr[mid];
        if (k - arr[mid] > 0 && k - arr[mid-1] <= 0)
            return arr[mid];

        if (k - arr[mid] >= 0)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}
