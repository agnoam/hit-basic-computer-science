#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "black_box.c"

#define R 3
#define C 7

typedef struct product {
    char* name;
    int price;
} Product;

int f1(int arr1[], int n1, int arr2[], int n2);
char* f2(Product p[], int n);
int f3(int Arr[], int n, int i);
void f4(int a[R][C]);

int main() {
    // Q1
    // int unique_arr[] = { 1, 2, 3, 4, 5 };
    // int arr2[] = { 4, 5, 4, 5, 6, 7, 8, 7, 8 };
    // printf("Should return 2: %d\n", f1(unique_arr, sizeof(unique_arr)/sizeof(unique_arr[0]), arr2, sizeof(arr2) / sizeof(int)));
    
    // int unique_arr2[] = { 1, 2, 3, 4, 5 };
    // int arr3[] = { 1,2,3,4,5,1,2,3,4,5 };
    // printf("Should return 5: %d\n", f1(unique_arr2, sizeof(unique_arr2)/sizeof(unique_arr2[0]), arr3, sizeof(arr3) / sizeof(int)));

    // Q2
    // Product arr[6] = { { "prodA", 10 }, { "prodB", 20 }, { "prodC", 15 }, { "prodD", 20 }, { "prodE", 20 }, { "prodF", 13 } };
    // printf("output string: %s\n", f2(arr, 6));

    // Q3
    // int arr[] = { 1,2,3,3,4,5 };
    // printf("output: %d\n", f3(arr, sizeof(arr)/sizeof(arr[0]), 3)); // Should print 2
    // printf("output: %d\n", f3(arr, sizeof(arr)/sizeof(arr[0]), 2)); // Should print 1
    // printf("output: %d\n", f3(arr, sizeof(arr)/sizeof(arr[0]), 6)); // Should print 0

    // Q4
    // Example:
    // 5  4  1  0  2  2  1
    // 0  4  0  5  3  0  2
    // 0  4  9  0  3  8  2
    // 5  12 10 5  8  10 5 => 5 12 10 8
    int matrix[R][C] = { 
        { 5, 4, 1, 0, 2, 2, 1 },
        { 0, 4, 0, 5, 3, 0, 2 },
        { 0, 4, 9, 0, 3, 8, 2 }
    };
    printf("output: \n");
    f4(matrix);
}

int f1(int arr1[], int n1, int arr2[], int n2) {
    int i, found;
    if (!n1)
        return 0;

    found = f1(arr1+1, n1-1, arr2, n2);
    for (i = 0; i < n2; i++) {
        if (arr1[0] == arr2[i]) {
            found++;
            break;
        }
    }

    return found;
}

/*
    Constraints:
    * The output string would not be more than 200 characters long.
*/
char* f2(Product p[], int n) {
    int i, max_price = 0, cursor_position = 0;
    char* str = calloc(200, sizeof(char));
    if (!str)
        return NULL;

    // Find the maximum price of the products
    for (i = 0; i < n; i++)
        if (p[i].price > max_price) max_price = p[i].price;
    
    // Concatenate the 
    for (i = 0; i < n; i++) {
        if (p[i].price == max_price) {
            if (cursor_position > 0 && str[cursor_position - 1]) {
                str[cursor_position] = ' '; // Adding a space after
                cursor_position++;
            }

            strcpy(str + cursor_position, p[i].name);
            cursor_position += strlen(p[i].name);
        }
    }

    cursor_position++; // For the ending \0
    return realloc(str, cursor_position);
}

/*
    Constraints: 
    * You can assume the input array is always sorted ascending order
*/
// In this year, the function `binary_search_left` and `binary_search_right` are not implemented. 
// So we will need to implement them, but in the other years you can use it as "black box" (you can look at the specific implementation in "black_box.c")
int f3(int Arr[], int n, int i) {
    int right = binary_search_right(Arr, n, i), left = binary_search_left(Arr, n, i);
    
    if (right == -1 || left == -1)
        return 0;

    return (right - left) + 1;
}

void f4(int a[R][C]) {
    int row, col, sum;
    int sum_arr[C] = {};
    
    for (col = 0; col < C; col++) {
        sum = 0;
        for (row = 0; row < R; row++)
            sum += a[row][col];
        
        sum_arr[col] = sum;
    }

    quick_sort(sum_arr, 0, C-1);
    for (col = 0; col < C; col++)
        if (sum_arr[col] != sum_arr[col+1]) printf("%d ", sum_arr[col]);
}
