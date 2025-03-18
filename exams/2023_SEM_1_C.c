#include <stdio.h>
#include <string.h>

#include "../black_box.c"

#define N 4

int diff_even_odd(int num);
int is_subsequence(char* str1, char* str2);
int is_Perfect(int* arr, int n);
void mat_sort_rev(int mat[N][N]);

void print_matrix(int mat[][N]) {
    printf("\n\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Q1
    // printf("res: %d\n", diff_even_odd(51637021)); // -5 + 3 = -2
    // printf("res: %d\n", diff_even_odd(12345)); // -3 + 2 = -1

    // Q2
    // printf("res: %d\n", is_subsequence("dbcabafacbcbd", "abcd")); // Should print: 1
    // printf("res: %d\n", is_subsequence("dbcabafacbcbd", "abcf")); // Should print: 0

    // Q3
    // int arr[] = { 3, 0, 1, 4, 2 };
    // printf("res: %d\n", is_Perfect(arr, sizeof(arr) / sizeof(arr[0]))); // Should print: 1
    // int arr2[] = { 3, 1, 0, 4, 2 };
    // printf("res: %d\n", is_Perfect(arr2, sizeof(arr2) / sizeof(arr2[0]))); // Should print: 0

    // Q4
    int mat[N][N] = {
        { 3, 6, 8, 11 },
        { 13, 16, 19, 20 },
        { 22, 33, 34, 50 },
        { 60, 63, 71, 74 },
    };

    printf("Source matrix: ");
    print_matrix(mat);
    mat_sort_rev(mat);
    printf("Ouput matrix: ");
    print_matrix(mat);
}

/* 
    Constraints: 
    * Function implementation should be recursive and efficient
    * You can assume that num is always positive
*/
int diff_even_odd(int num) {
    // Less than 2 digits
    if (num < 10)
        return num % 2 ? -1 : 1;

    if (!((num % 10) % 2))
        return 1 + diff_even_odd(num / 10);
    return -1 + diff_even_odd(num / 10);
}

/*
    Constraints:
    * Function runtime complexity should be O(n) where n is the number of letters in the two strings
    * You can assume that the letters in the strings will always be lower case
*/
int is_subsequence(char* str1, char* str2) {
    int i, temp_int, str1_i = 0;
    char* temp;
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);

    // Ensuring that always str1 is longer than str2
    if (str1_len > str2_len) {
        temp = str1;
        str1 = str2;
        str2 = temp;

        temp_int = str1_len;
        str1_len = str2_len;
        str2_len = temp_int;
    }
    
    for (i = 0; i < str2_len; i++) {
        if (str2[i] == str1[str1_i]) {
            if (str1_i + 1 < str1_len) str1_i++;
            else return 1;
        }
    }

    return 0;
}

/*
    3.a:
        This is an example for an array that will result 0 in `is_Perfect()`: [3, 1, 0, 4, 2]
        Short answer: because of the element: `1`. 
        Full description: 
            According to the question details, the array should reference to each of the elements in the given array.
            In the example given: [3, 0, 1, 4, 2]
                arr[0] = 3 -> arr[3] = 4 -> arr[4] 2 -> arr[2] 1 -> arr[1] 0 -> arr[0] 3
                All of the elements were referenced.

            In the example of failure, There is an element which is not referenced.
            [3, 1, 0, 4, 2]
            arr[0] = 3 -> arr[3] = 4 -> arr[4] 2 -> arr[2] 0 -> arr[0] = 3
            Which makes the array element `1` (arr[1]) to be not referenced.
*/

/*
    Constraints:
    * Array elements range will always be at the range [0, n-1]
    * Can not use extra arrays
    * Runtime complexity should be O(n)
*/
int is_Perfect(int* arr, int n) {
    int i = 0, last_val;

    while (i < n && i >= 0) {
        last_val = arr[i];
        arr[i] = -1; // Signals the element as seen

        if (arr[i] == i) i++; // Should support the option of [1, 2, 3, 4]
        else i = last_val; // Should support the option of [3, 0, 1, 4, 2]
    }

    for (i = 0; i < n; i++)
        if (arr[i] != -1) return 0;
    return 1;
}

/*
    Constraints:
    * Function runtime complexity should be O(NxN => n^2)
    * N will always be even number
    * The implementation should not use extra array
    * The input `mat` will always be sorted ascending order
*/
void mat_sort_rev(int mat[N][N]) {
    int right, left = (N * N) - 1;

    for (right = 0; right < (N*N) / 2; right++)
        swap((int*) mat + right, (int *) mat + left--);
}
