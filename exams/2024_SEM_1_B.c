#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../black_box.c"

int* valueNotInArray(int* arr, int n, int* newSize);
int find_two_digits(char* number);
int is_zero(int* pos, int n, int* neg, int m);
int number_returns(int* arr, int size);

int main() {
    printf("\n\n");
    // int arr[] = { 0, 1, 1, 0, 3, 5 };
    // int arr[] = { };
    // int newSize;
    //
    // int* new_arr = valueNotInArray(arr, sizeof(arr) / sizeof(arr[0]), &newSize);
    // if (!new_arr)
    //     printf("new array is null\n");
    //
    // printf("not_in_array: ");
    // print_array(new_arr, newSize);
    //
    // char str[] = "12121212121";
    // printf("recurrent num: %d", find_two_digits(str));
    // char str2[] = "21212121212";
    // printf("recurrent num: %d", find_two_digits(str2));
    // char str3[] = "222211";
    // printf("recurrent num: %d", find_two_digits(str3));

    // int pos[] = { 1, 4, 8, 11 };
    // int neg[] = { -20, -15, -11, -3, -2 };
    // printf("found zero: %d\n", is_zero(pos, sizeof(pos) / sizeof(int), neg, sizeof(neg) / sizeof(int)));
    //
    // int pos2[] = { 1, 4, 8, 11 };
    // int neg2[] = { -20, -15, -12, -3, -2 };
    // printf("found zero: %d\n", is_zero(pos2, sizeof(pos2) / sizeof(int), neg2, sizeof(neg2) / sizeof(int)));

    int arr[] = { 1, 2, -3005, 2, 3, 1, -1000, 3, 7, -11, 2, 15, 2, 3, 90, 7, 2, 2, 1000 };
    printf("%d", number_returns(arr, sizeof(arr) / sizeof(int)));
    return 0;
}

int* valueNotInArray(int* arr, int n, int* newSize) {
    int* output_arr = calloc(n || 1, sizeof(int));
    int* resized_arr;

    if (!output_arr)
        return output_arr; // Returning null value

    *newSize = 0;
    for (int i = 0; i <= n; i++) {
        if (binary_search(arr, n, i) == -1)
            output_arr[(*newSize)++] = i;
    }

    // Error handling
    resized_arr = realloc(output_arr, *newSize * sizeof(int));
    if (!resized_arr) {
        free(output_arr);
        return NULL;
    }

    return output_arr;
}

int convert_two_digs_to_int(char* number) {
    return (number[0] - '0') * 10 + (number[1] - '0');
}

int find_two_digits(char* number) {
    int i, max_index = 0, char_len = strlen(number);
    int* count_arr = calloc(100, sizeof(int));

    // Allocation error handling
    if (!count_arr)
        return -1;

    // Fill count arr
    for (i = 0; i < char_len-1; i++)
        count_arr[convert_two_digs_to_int(&number[i])]++;

    for (i = 0; i < 100; i++)
        if (count_arr[i] > count_arr[max_index]) max_index = i;
    
    free(count_arr);
    return max_index;
}

// int is_zero(int* pos, int n, int* neg, int m) {
//     if (n < 0)
//         return 0;
//
//     for (int i = 0; i < m; i++)
//         if (!(pos[n-1] + neg[i])) return 1;
//
//     return is_zero(pos, --n, neg, m);
// }

int is_zero(int* pos, int n, int* neg, int m) {
    if (n == 0)
        return 0;

    if (!(pos[n-1] + neg[m-1]))
        return 1;

    if (m > 1)
        return is_zero(pos, n, neg, --m);
    return is_zero(pos, --n, neg, m);
}

int number_returns(int* arr, int size) {
    int i, max_count = 1, current_count = 1;
    quick_sort(arr, 0, size-1);

    // Array is sorted
    for (i = 0; i < size; i++) {
        if (arr[i] == arr[i+1])
            current_count++;
        else
            current_count = 1;

        if (current_count > max_count)
            max_count = current_count;
    }

    return max_count;
}