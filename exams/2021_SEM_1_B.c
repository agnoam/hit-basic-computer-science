#include <stdio.h>
#include <stdlib.h>

#include "black_box.c"

#define R 4
#define C 5

int isSumPairsNotIncreasing(int n);
int ItemEqualIndex(double* array, int size);
void sort_arr_by_params(int* arr, int n, int a, int b);
int count_lonelies(int m[R][C]);

int main() {
    printf("\n\n");

    // Q1
    printf("Should print 1: %d\n", isSumPairsNotIncreasing(81623350));
    printf("Should print 1: %d\n", isSumPairsNotIncreasing(12));

    // Q2
    double _arr[] = { -9, -5.2, 0, 3, 12.2 };
    printf("Should return 3: %d\n", ItemEqualIndex(_arr, sizeof(_arr) / sizeof(_arr[0])));

    double __arr[] = { 0, 2, 5, 8.1, 4 };
    printf("Should return 4/0: %d\n", ItemEqualIndex(__arr, sizeof(__arr) / sizeof(__arr[0])));

    double arr_[] = { 1, 2, 5, 8, 17 };
    printf("Should return -1: %d\n", ItemEqualIndex(arr_, sizeof(_arr) / sizeof(arr_[0])));


    // Q3
    int arr[] = { 12, 10, 5, 9, -15, 2 };
    sort_arr_by_params(arr, sizeof(arr) / sizeof(arr[0]), -1, 9);
    printf("Output Arr: ");
    print_array(arr, sizeof(arr) / sizeof(arr[0]));

    int arr2[] = { 12, 10, 5, 9, -15, 2 };
    sort_arr_by_params(arr2, sizeof(arr2) / sizeof(arr2[0]), 6, 11);
    printf("Output Arr: ");
    print_array(arr2, sizeof(arr2) / sizeof(arr2[0]));

    int arr3[] = { 12, 10, 5, 9, -15, 2 };
    sort_arr_by_params(arr3, sizeof(arr3) / sizeof(arr3[0]), -200, 100);
    printf("Output Arr: ");
    print_array(arr3, sizeof(arr3) / sizeof(arr3[0]));
    
    // Q4
    int m[R][C] = {
        { 0,5,0,0,2 },
        { 0,0,0,3,0 },
        { 0,6,0,0,0 },
        { 0,0,0,0,1 },
    };

    printf("source matrix: \n");
    print_matrix((int*) m, R, C);
    printf("Should print 3: %d", count_lonelies(m));

    return 0;
}

int isSumPairsNotIncreasing(int n) {
    if (n < 1000)
        return 1; // Less than 4 digits

    if ((n % 10) + ((n / 10) % 10) <= ((n / 100) % 10) + ((n / 1000) % 10))
        return isSumPairsNotIncreasing(n / 1000);
    
    return 0;
}

int ItemEqualIndex(double* array, int size) {
    int left = 0, right = size - 1, mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (array[mid] == mid) {
            return mid;
        } else if (array[mid] < mid) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }

    return -1;
}

void sort_arr_by_params(int* arr, int n, int a, int b) {
    int less_a_cursor = 0, less_b_cursor = 0, greater_b_cursor = 0, i;
    int* less_a_arr = (int*) malloc(n*sizeof(int));
    int* less_b_arr = (int*) malloc(n*sizeof(int));
    int* greater_b_arr = (int*) malloc(n*sizeof(int));

    if (!less_a_arr || !less_b_arr || !greater_b_arr) {
        printf("Memory allocation failed\n");
        return;
    }

    for (i = 0; i < n; i++) {
        if (arr[i] <= a)
            less_a_arr[less_a_cursor++] = arr[i];
        else if (arr[i] <= b)
            less_b_arr[less_b_cursor++] = arr[i];
        else
            greater_b_arr[greater_b_cursor++] = arr[i];
    }

    for (i = 0; i < n; i++) {
        if (less_a_cursor) 
            arr[i] = less_a_arr[--less_a_cursor];
        else if (less_b_cursor)
            arr[i] = less_b_arr[--less_b_cursor];
        else
            arr[i] = greater_b_arr[--greater_b_cursor];
    }

    free(less_a_arr);
    free(less_b_arr);
    free(greater_b_arr);
}

int is_lonely(int m[R][C], int target_r, int target_c) {
    if (target_r - 1 >= 0) {
        if (m[target_r-1][target_c]) return 0;
        if (target_c + 1 < C && m[target_r-1][target_c+1]) return 0;
        if (target_c - 1 >= 0 && m[target_r-1][target_c-1]) return 0;
    }

    if (target_r + 1 < R) {
        if (m[target_r + 1][target_c]) return 0;
        if (target_c + 1 < C && m[target_r + 1][target_c + 1]) return 0;
        if (target_c-1 >= 0 && m[target_r + 1][target_c - 1]) return 0;
    }

    if (target_c - 1 >= 0 && m[target_r][target_c - 1]) return 0;
    if (target_c + 1 < C && m[target_r][target_c + 1]) return 0;

    return 1;
}

int count_lonelies(int m[R][C]) {
    int i, j, counter = 0;
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (m[i][j]) 
                counter += is_lonely(m, i, j);
        }
    }

    return counter;
}
