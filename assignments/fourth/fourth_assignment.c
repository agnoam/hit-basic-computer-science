#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>


// Black box functions declarations

void print_array(int* arr, int n);

//////////////////////////////////////

int findCommonDigit(unsigned long long n1, unsigned long long n2);
int moveDuplicatesV1(int* arr, int n);
int moveDuplicatesV2(int* arr, int n);

int main() {
    int q_number, n;

    printf("Enter the number of question to run (1-4): ");
    scanf("%d", &q_number);

    switch (q_number) {
        case 1:
            int n2;
            printf("Enter two numbers to find the common digit between them (format `n1 n2`): ");
            scanf("%d%d", &n, &n2);
            
            int found_digit = findCommonDigit(n, n2);
            printf(found_digit == -1 ? "There is no common digit" : "The common digit is: %d", found_digit);
            break;

        case 2:
            // printf("Enter number to return the count of ones in it's binary representation: ");
            // scanf("%d", &n);

            int arr[] = { 7, 3, 1, 2, 7, 9, 3, 2, 5, 9, 6, 2 };
            // int arr[] = { 1, 2, 1, 3 };

            int n = sizeof(arr) / sizeof(int);
            // int new_length = moveDuplicatesV1(arr, n);
            int new_length = moveDuplicatesV2(arr, n);
            printf("new length: %d\n", new_length);
            print_array(arr, n);
            break;

        // case 3:
        //     printf("Enter a decimal positive number to calculate the delta between the even digits and odd digits sums: ");
        //     scanf("%d", &n);
        //     printf("The delta is: %d", diff(n));
        //     break;

        // case 4:
        //     printf("Enter the length of the input list: ");
        //     scanf("%d", &n);
        //     bigger_rev(n);
        //     break;

        default:
            printf("Invalid question number");
            return 1;
    }

    return 0;
}

// Those are a "black box" functions that can be used without implementation

/*
    Swaps between two integers. 

    Parameters:
        `a` - First pointer to to swap
        `b` - Second pointer to swap
*/
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
    Prints an array of integers
    Parameters:
        `arr` - An int pointer to the first element of the array
        `n` - The length of the given array
*/
void print_array(int* arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++)
        printf(i == n-1 ? "%d" : "%d, ", arr[i]);
    printf("]\n");
}

/*
    Partitions the array around a pivot element.

    Parameters:
        `arr` - Pointer to the array to be partitioned.
        `low` - Starting index of the array segment.
        `high` - Ending index of the array segment.

    Returns:
        The partition index (`j`), where all elements to the left of `j` 
        are less than or equal to the pivot, and all elements to the right 
        of `j` are greater than the pivot.
*/
int partition(int* arr, int low, int high) {
    // Initialize pivot to be the first element
    int p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        // Find the first element greater than
        // the pivot (from starting)
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }

        // Find the first element smaller than
        // the pivot (from last)
        while (arr[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]);
    return j;
}


/*
    Sorts an array in ascending order using the Quick Sort algorithm.

    Parameters:
        `arr` - Pointer to the array to be sorted.
        `low` - Starting index of the array segment.
        `high` - Ending index of the array segment.
*/
void quick_sort(int* arr, int low, int high) {
    if (low < high) {
        // call partition function to find Partition Index
        int pi = partition(arr, low, high);

        // Recursively call quick_sort() for left and right
        // half based on Partition Index
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

/*
    Searches for a target value in a sorted array using the Binary Search algorithm.

    Parameters:
        `array` - Pointer to the sorted array.
        `size` - Size of the array.
        `target` - The value to be searched for.

    Returns:
        If the target is found, the function returns its index in the array.
        Otherwise, it returns `-1`.
*/
int binary_search(int* array, int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // To prevent potential overflow

        if (array[mid] == target) {
            return mid; // Target found at index mid
        } else if (array[mid] < target) {
            low = mid + 1; // Search the right half
        } else {
            high = mid - 1; // Search the left half
        }
    }

    return -1; // Target not found
}

/////////////////////////////////////////////////////////////////////////////

/*
    Finds the common digits between `n1` and `n2`.
    
    Parameters:
        `n1` - Very long number
        `n2` - Another very long number 
    
    Returns:
        In case there is a common digit, the function will return it.
        Otherwise it will return `-1`.
*/
int findCommonDigit(unsigned long long n1, unsigned long long n2) {
    if (!n1) 
        return -1;
        
    if (n1 % 10 > n2 % 10)
        // Trimming `n1`
        return findCommonDigit(n1 / 10, n2);

    else if (n1 % 10 < n2 % 10)
        // Trimming `n2`
        return findCommonDigit(n1, n2 / 10);

    return n1 % 10;
}

/*
    Returns the `min` and `max` values within the given array.

    Parameters:
        `arr` - Pointer to the first element of the array
        `length` - Length of the array
        `min` - Minimum value of the array (assumed uninitialized)
        `max` - Maximum value of the array (assumed uninitialized)
*/
void range_of_array(int* arr, int length, int *min, int *max) {
    int i;

    *min = INT_MAX;
    *max = INT_MIN;

    for (i = 0; i < length; i++) {
        if (arr[i] > *max) *max = arr[i];
        if (arr[i] < *min) *min = arr[i];
    }
}

/*
    Generates an array with all the numbers from `min` to `max` as indecies (including zero)
    In each of the elements will be `1/0` that indicates whether the number is already seen in the given array or not.

    Parameters:
        `input_arr` - The array to scan
        `n` - The length of `input_arr`
        
        FYI: The source variables can be uninitialized
        `unique_count` - Pointer to an int variable that holds the count of all the unique values
        `zero_index` - Pointer to an int variable that holds the index of the value `0` in the output array

    Returns:
        `Pointer` to the first element of the output array or 
        `NULL` whether the memory allocation for the output array was failed.
*/
int* generate_unique_array(int* input_arr, int n, int* unique_count, int* zero_index) {
    int i, min, max;
    range_of_array(input_arr, n, &min, &max);
    *unique_count = 0; // Initializing pointer value
    *zero_index = min < 0 ? abs(min) : 0;

    int* unique_arr = (int*) calloc((max-min)+1 +1, sizeof(int));
    if (!unique_arr)
        return NULL;

    for (i = 0; i < n; i++) {
        // Starting the count from the minimum value
        int val = *zero_index + input_arr[i];
        if (!unique_arr[val]) {
            unique_arr[val] = 1;
            *unique_count = *unique_count + 1;
        }
    }

    return unique_arr;
}

/*
    Moves the duplicates to the end of the array,
    while maintaining the order of the unique values in the array.

    Parameters:
        `arr`: Pointer to the first element of the array
        `n`: The length of the array

    Returns:
        The count of unique elements or `-1` in case of an error.
*/
int moveDuplicatesV1(int* arr, int n) {
    int i, unique_count, zero_index, current_num, replace_index = -1;
    int* unique_arr = NULL;

    unique_arr = generate_unique_array(arr, n, &unique_count, &zero_index);
    if (!unique_arr) {
        printf("Memory allocation failed\n");
        return -1;
    }

    for (i = 0; i < n; i++) {
        current_num = arr[i];
        if (replace_index == -1 && !unique_arr[zero_index + current_num]) {
            replace_index = i;
        } else if (replace_index != -1 && unique_arr[zero_index + current_num]) {
            unique_arr[zero_index + current_num] = 0;
            swap(&arr[i], &arr[replace_index]);
            replace_index++;
            
            // Finding the next duplicate element whitin the subarray
            for (int j = replace_index; j < i; i++) {
                if (!unique_arr[zero_index + arr[j]]) break;
                replace_index = j;
            }
        } 
        
        // Marking the number as duplicate (because already read once)
        unique_arr[zero_index + current_num] = 0;
    }

    free(unique_arr);
    unique_arr = NULL;

    return unique_count;
}

/*
    Duplicates an integer array
    
    Parameters:
        `arr` - The integer array to duplicate
        `n` - The length of the array

    Returns:
        Pointer to the new duplicated array or 
        `NULL` in case of allocation error
*/
int* duplicate_arr(int* arr, int n) {
    int i;
    int* dup = malloc(n * sizeof(int));

    if (dup) {
        for (i = 0; i < n; i++)
            dup[i] = arr[i];
    }

    return dup;
}

/*
    Takes sorted integer array and creates new array with unique values only
    Parameters:
        `arr`: The array to remove the duplicates from
        `n`: The length of the array
        `unique_arr_length`: The new length of the output array

    Returns:
        New array with unique values only, in case of failure the function will return `NULL`
*/
int* remove_duplicates(int* arr, int n, int* unique_arr_length) {
    int i, last_value, last_inserted_i = 0, unique_count = 0;
    int* unique_arr = NULL;

    // Counting the unique values
    for (i = 0; i < n; i++) {
        if (i == 0 || arr[i] != last_value) {
            unique_count++;
            last_value = arr[i];
        }
    }

    // Inserting the values 
    unique_arr = calloc(unique_count, sizeof(int));
    if (unique_arr) {
        for (i = 0; i < n; i++) {
            if (i == 0 || arr[i] != last_value) {
                unique_arr[last_inserted_i] = arr[i];
                last_value = arr[i];
                last_inserted_i++;
            }
        }

        *unique_arr_length = unique_count;
    }

    return unique_arr;
}

/*
    Generates an array of all the unique values from the `input_array` sorted accending order

    Parameters:
        `input_arr` - The input array to scan
        `n` - The length of the `input_arr`
        `count` - The length of the output array

    Returns:
        A pointer to the first element of the array or `NULL` in case of an error.

    Example:
        input array: [7, 3, 1, 2, 7, 9, 3, 2, 5, 9, 6, 2]
        output array: [1, 2, 3, 5, 6, 7, 9]
*/
int* generate_sorted_unique_array(int* input_arr, int n, int* count) {
    int* duplicate;
    int* unique_arr;

    duplicate = duplicate_arr(input_arr, n);
    if (!duplicate) {
        printf("Memory allocation error!");
        return duplicate;
    }

    // Sorting the whole array
    quick_sort(duplicate, 0, n-1);
    unique_arr = remove_duplicates(duplicate, n, count);

    free(duplicate);
    duplicate = NULL;
    return unique_arr; // Could be null as well
}

/*
    Removes an element from an integer array

    Parameters:
        `arr` - The array to modify
        `n` - The current length of the array

    Returns:
        The new length of the array after the change
*/
int remove_element(int* arr, int index_to_remove, int length) {
    int i;
    
    if (length < 1)
        return length;

    for(i = index_to_remove; i < length - 1; i++) 
        arr[i] = arr[i + 1];
}

/*
    Moves the duplicates to the end of the array,
    while maintaining the order of the unique values in the array.

    Parameters:
        `arr`: Pointer to the first element of the array
        `n`: The length of the array

    Returns:
        The count of unique elements or `-1` in case of an error.
*/
int moveDuplicatesV2(int* arr, int n) {
    int i, unique_count, original_unique_count, current_num, found_index, replace_index = -1;
    int* unique_arr = NULL;

    unique_arr = generate_sorted_unique_array(arr, n, &unique_count);
    original_unique_count = unique_count;
    if (!unique_arr) {
        printf("Memory allocation failed\n");
        return -1;
    }

    for (i = 0; i < n; i++) {
        current_num = arr[i];
        found_index = binary_search(unique_arr, unique_count, current_num);

        if (replace_index == -1 && found_index == -1) {
            replace_index = i;
        } else if (replace_index != -1 && found_index != -1) {
            unique_count = remove_element(unique_arr, found_index, unique_count);
            swap(&arr[i], &arr[replace_index]);
            replace_index++;
            
            // Finding the next duplicate element whitin the subarray
            for (int j = replace_index; j < i; i++) {
                if (binary_search(unique_arr, unique_count, arr[j]) == -1) break;
                replace_index = j;
            }
        } else if (found_index != -1) {
            unique_count = remove_element(unique_arr, found_index, unique_count);
        }
    }

    free(unique_arr);
    unique_arr = NULL;
    return original_unique_count;
}
