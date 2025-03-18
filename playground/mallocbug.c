/* 
    This is an example to show what will happen in case a c program would not free
    unused arrays.

    Before you run this code open up your task-manager in order to see what will happen and learn from it.
*/

#include <stdio.h>
#include <stdlib.h>

// Function definitions
int* push_arr(int *arr, int *lenP, int input);
int check_allocation(int *new_alloc);
int* push_with_free(int *arr, int *lenP, int input);
int* push_realloc(int *arr, int *lenP, int input);
void freeze();


int main() {
    int *arr = (int*) malloc(0);
    int wanted_len, input, len = 0;
    
    printf("Max size of array to check: ");
    scanf("%d", &wanted_len);

    for (int i = 0; i < wanted_len; i++)
        arr = push_realloc(arr, &len, i);
    
    printf("Alternating array using realloc\n");
    freeze();
    free(arr);
    len = 0;
    arr = NULL;

    for (int i = 0; i < wanted_len; i++)
        arr = push_with_free(arr, &len, i); // Memory fregmentation error
    
    printf("Alternating array using free\n");
    freeze();
    free(arr);
    len = 0;
    arr = NULL;

    for (int i = 0; i < wanted_len; i++)
        arr = push_arr(arr, &len, i); // Memory deallocation error
    
    freeze();
    free(arr);
    printf("Alternating arrays until end\n");

    return 0;
}

void freeze() {
    int input;

    printf("Write number to continue: ");
    scanf("%d", &input);
}

// Has a bug intentionally
int* push_arr(int *arr, int *lenP, int input) {
    // Creating pointer to new array
    int len = *lenP;
    int *new_arr = (int*) malloc(++len * sizeof(int));
    for (int i = 0; i < len; i++)
        new_arr[i] = (i < len - 1) ? arr[i] : input;
        
    *lenP = len;
    return new_arr;
}

int* push_with_free(int *arr, int *lenP, int input) {
    // Creating pointer to new array
    int len = *lenP;
    int *new_arr = (int*) malloc(++len * sizeof(int));
    for (int i = 0; i < len; i++)
        new_arr[i] = (i < len - 1) ? arr[i] : input;

    if (arr != NULL)    
        free(arr);

    *lenP = len;
    return new_arr;
}

// Checking whther the memory allocation failed
int check_allocation(int *new_alloc) {
    if (new_alloc == NULL) {
        // Handle reallocation failure (e.g., memory exhaustion)
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1); 
    }
}

int* push_realloc(int *arr, int *lenP, int input) {
    int len = *lenP;
    int *new_arr = (int*) realloc(arr, ++len * sizeof(int));
    check_allocation(new_arr);
    new_arr[len-1] = input;
    
    *lenP = len;
    return new_arr;
}