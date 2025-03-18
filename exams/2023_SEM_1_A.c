#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../black_box.c"

#define R 5
#define C 6

void sortpairs(int* a, int size);
void squeeze(char* str);
int* distsort(int* a, int n, int num);
int waterfill(int valley[R][C], int cloud_r, int cloud_c, int cloud_h);

int main() {
    printf("\n\n");

    // Q1
    // int arr[] = { 1, 2, 3, 7, 8, 9 };
    // int arr2[] = { 2, 2, 5, 7, 12, 12 };
    // int len = sizeof(arr) / sizeof(arr[0]);
    
    // sortpairs(arr, len);
    // printf("result: ");
    // print_array(arr, len);

    // sortpairs(arr2, len);
    // printf("result: ");
    // print_array(arr2, len);

    // Q2
    // char str[] = "dbcabafacbcbdd";
    // squeeze(str);
    // printf("result string: %s", str);

    // Q3
    // int arr[] = { 1, 2, 5, 7, 10 };
    // int len = sizeof(arr) / sizeof(int);
    // printf("result array: ");
    // print_array(distsort(arr, len, 5), len);
    
    // printf("result array: ");
    // print_array(distsort(arr, len, 7), len);

    // int arr2[] = { 1,2,3 };
    // len = sizeof(arr2) / sizeof(int);
    // printf("result array: ");
    // print_array(distsort(arr2, len, 2), len);
    
    int matrix[R][C] = { 
        { 255, 255, 255, 255, 255, 255 },
        { 255, 20,  62,  10,  1,   255 },
        { 255, 25,  27,  50,  1,   255 },
        { 255, 30,  63,  2,   1,   255 },
        { 255, 255, 255, 255, 255, 255 },
    };

    printf("total water rained: %d\n", waterfill(matrix, 1,1, 50));
    printf("total water rained: %d\n", waterfill(matrix, 1, 4, 2));
    return 0;
}

void sortpairs(int* a, int size) {
    int i, end = size - 1;
    for (i = 1; i < size / 2; i+=2)
        swap(&a[i], &a[end--]);

    /* 
        Due to the constraints of the question, 
        we can assume that the array is always sorted and there are always pairs.
        
        Because of the 
    */
}


void squeeze(char* str) {
    int i, replace_index = 0, len = strlen(str);
    int seen_arr[26] = { 0 };

    // Fill the `seen_arr` with the count of the each letter
    for (i = 0; i < len; i++)
        seen_arr[str[i] - 'a']++;

    // Search for the letters with '3' occurences and
    for (i = 0; i < len; i++) {
        if (seen_arr[str[i] - 'a'] != 3)
            continue;

        str[replace_index++] = str[i];
        seen_arr[str[i] - 'a'] = 0;
    }

    str[replace_index] = '\0';
}


int find_min_index(int* a, int n, int num) {
    int i;
    for (i = 0; i < n; i++) {
        if (!abs(a[i] - num))
            return i;
    }
}

int* distsort(int* a, int n, int num) {
    int i, zero_index, left_i = 0, right_i;
    int* output_arr = malloc(n * sizeof(int));

    if (!output_arr)
        return NULL;

    zero_index = find_min_index(a, n, num);
    left_i = zero_index-1;
    right_i = zero_index+1;
    for (i = 0; i < n; i++) {
        if (!i) {
            output_arr[i] = a[zero_index];
        } else if (abs(a[i] - a[left_i]) <= abs(a[i] - a[right_i])) {
            output_arr[i] = a[left_i];
            if (left_i) left_i--;
        } else {
            output_arr[i] = a[right_i];
            if (right_i < n-1) right_i++;
        }
    }

    return output_arr;
}

/**
    Constraints: 
    * The function have to be recursive
    * The clouds won't be at the matrix boundries
    * The cloud height will always be at the range [0, 150]
*/
int waterfill(int valley[R][C], int cloud_r, int cloud_c, int cloud_h) {
    if (cloud_r < 0 || cloud_r >= R || cloud_c < 0 || cloud_c >= C || valley[cloud_r][cloud_c] >= cloud_h)
        return 0;

    int current_val = abs(cloud_h - valley[cloud_r][cloud_c]);
    valley[cloud_r][cloud_c] = cloud_h; // Disabling this value for the further calculation

    // Lets assume (1,1)
    return current_val + 
        waterfill(valley, cloud_r, cloud_c-1, cloud_h) + // Upwards (1, 0)
        waterfill(valley, cloud_r+1, cloud_c, cloud_h) + // To the right (2, 1)
        waterfill(valley, cloud_r-1, cloud_c, cloud_h) + // Left (0, 1)
        waterfill(valley, cloud_r, cloud_c+1, cloud_h); // Down (1, 2)
}
