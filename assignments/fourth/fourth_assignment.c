#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>

void print_array(int* arr, int n);

int findCommonDigit(unsigned long long n1, unsigned long long n2);
int moveDuplicatesV1(int* arr, int n);
int moveDuplicatesV2(int* arr, int n); 
int stringPermutation(char* str);
int validateArray(int* arr, int n);

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
            int arr[] = { 7, 3, 1, 2, 7, 9, 3, 2, 5, 9, 6, 2 };

            int n = sizeof(arr) / sizeof(int);
            // int new_length = moveDuplicatesV1(arr, n);
            int new_length = moveDuplicatesV2(arr, n);
            printf("new length: %d\n", new_length);
            print_array(arr, n);
            break;

        case 3:
            char str[100] = "abdc"; // => "acbd"
            int is_changed = stringPermutation(str);
            
            printf("is_changed: %d\n", is_changed);
            if (is_changed)
                printf("source string changed: %s\n", str);

            break;

        case 4:
            int num_arr[] = { 1, 2, 3, 0, 4, 5 };
            printf("is validated: %d", validateArray(num_arr, sizeof(num_arr) / sizeof(int)));
            int arr_2[] = { 1, 2, 1, 0, 4, 5 };
            printf("is validated: %d", validateArray(arr_2, sizeof(arr_2) / sizeof(int)));
            break;

        default:
            printf("Invalid question number");
            return 1;
    }

    return 0;
}

// Those are a "black box" functions that can be used without implementation

/**
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

/**
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

/**
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

/**
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

/**
 * Find the left-most (lower bound) index of specific target (element)
 * 
 * @param arr A sorted integers array to search in
 * @param n The size of the array (elements count)
 * @param target The element to search for
 * 
 * @returns The left most element index of the target element or `-1` if no such element found
 */
int binary_search_left(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (abs(arr[mid]) == target) {
            result = mid;
            high = mid - 1;
        } else if (abs(arr[mid]) < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

/////////////////////////////////////////////////////////////////////////////
// Utils

/**
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

////////////////////////////////////////////////////////////////////////////

/**
    Finds the common digits between `n1` and `n2`.
    
    @param n1 Very long number
    @param n2 Another very long number 
    
    @returns In case there is a common digit, the function will return it.
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

/**
    Returns the `min` and `max` values within the given array.

    @param arr Pointer to the first element of the array
    @param length Length of the array
    @param min Minimum value of the array (assumed uninitialized)
    @param max Maximum value of the array (assumed uninitialized)
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

/**
    Generates an array with all the numbers from `min` to `max` as indecies (including zero)
    In each of the elements will be `1/0` that indicates whether the number is already seen in the given array or not.

    @param input_arr The array to scan
    @param n The length of `input_arr`
        
    FYI: The referenced variables can be uninitialized
    @param unique_count Pointer to an int variable that holds the count of all the unique values
    @param zero_index Pointer to an int variable that holds the index of the value `0` in the output array

    @returns `Pointer` to the first element of the output array or `NULL` whether the memory allocation for the output array was failed.
*/
int* generate_unique_array(int* input_arr, int n, int* unique_count, int* zero_index) {
    int i, min, max;
    range_of_array(input_arr, n, &min, &max);
    *unique_count = 0; // Initializing pointer value
    *zero_index = min < 0 ? abs(min) : 0;

    int* unique_arr = (int*) calloc((max-min) + 1, sizeof(int));
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

/**
    Moves duplicates to the end of the array while maintaining the order of unique elements.

    @param arr Pointer to the first element of the array 
    (each element should not be greater the `n` and smaller than `-n`)
    @param n The length of the array

    @returns The count of unique elements or -1 if an error occurs.
*/
int moveDuplicatesV1(int* arr, int n) {
    int unique_count, zero_index;
    int* unique_arr = generate_unique_array(arr, n, &unique_count, &zero_index);
    if (!unique_arr) {
        printf("Memory allocation failed\n");
        return -1;
    }

    int replace_index = 0; // Tracks where the next duplicate should go
    for (int i = 0; i < n; i++) {
        int val = arr[i] + zero_index;
        if (unique_arr[val]) {
            // Keep unique elements at the start of the array
            if (i != replace_index)
                swap(&arr[i], &arr[replace_index]);

            replace_index++;
            unique_arr[val] = 0; // Mark as processed
        }
    }

    free(unique_arr);
    return unique_count;
}

/**
 * Checking whether a `target` element is exists in the given `array`
 * 
 * FYI: The function alters the array!
 * 
 * @param arr The array to search in (should be sorted)
 * @param n The elements count of the given `arr`
 * @param target Which element to search for
 * 
 * @returns `0` | `1` Value representing whether the element already exists
 */
int is_exists(int *arr, int n, int target) {
    int result = binary_search_left(arr, n, target);

    // In case `temp` has negative number, then we already saw this number
    if (arr[result] < 0)
        return 1;

    // Assgining negative value to the found position
    arr[result] = -arr[result];
    return 0;
}

/**
    Moves duplicates to the end of the array while maintaining the order of unique elements.

    @param arr Pointer to the first element of the array
    @param n The length of the array

    @returns The count of unique elements or -1 if an error occurs.
*/
int moveDuplicatesV2(int* arr, int n) {
    int i, neg_number_count = 0;

    // Allocating and filling an array with the same elements
    int* temp = (int*) malloc(n * sizeof(int));
    if (!temp) return -1;

    for (i = 0; i < n; i++)
        temp[i] = arr[i];

    // Sorting `temp` array
    quick_sort(temp, 0, n - 1);
    for (i = 0; i < n; i++) {
        if (!is_exists(temp, n, arr[i]))
            arr[i] = -arr[i];
    }

    // Counting the negative elements in `temp` array
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0)
            temp[neg_number_count++] = arr[i];
    }

    // Sorting the source array (`arr`) and turning back each negative value to positive
    quick_sort(arr, 0, n - 1);
    for (i = 0; i < neg_number_count; i++)
        arr[i] = -temp[i];

    free(temp);
    return neg_number_count;
}

/**
    Swap between two characters

    @param a Pointer to the first character to swap
    @param b Pointer to the second character to swap
*/
void swap_str(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

/**
    Reversing the order of the string array

    @param start_i The starting index of reversing
    @param end_i The ending index of the reversing
*/
void reverse(char* start_i, char* end_i) {
    while (start_i != end_i && end_i > start_i && start_i && end_i) {
        swap_str(start_i, end_i);
        start_i++;
        end_i--;
    }
}

/**
    Replaces the string with the next bigger lexicographic permutation string

    @param str Pointer to the first element of the string
    @returns In case the string changed returned `1` else `0`
*/
int stringPermutation(char *str) {
    int length = strlen(str);
    if (length < 2) 
        return 0;

    // Find the pivot (The first element that is smaller than the one before)
    int i = length - 2;
    while (i >= 0 && str[i] >= str[i + 1]) 
        i--;

    // No greater permutation exists
    if (i < 0) 
        return 0;

    // Find successor
    int j = length - 1;
    while (str[j] <= str[i]) 
        j--;

    swap_str(&str[i], &str[j]); // Swap pivot and successor
    reverse(&str[i + 1], &str[length - 1]); // Reverse suffix

    return 1;
}

/**
    Validates whether the given array is contains all the possible values between (0 -> n-1)
    
    (Note: This funciton modifies the original order of the given array
    FYI: This function assumes the input array values are non-negative 
    and within the valid range. Behavior is undefined otherwise.)

    @param arr Pointer to the first element of the integer array to be validated
    @param n Size of the array.

    @returns `1` if the array is valid (no duplicates and can be rearranged),
    or `0` if a duplicate is found.
*/
int validateArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == i)
            continue;

        do {
            // Found duplicate
            if (arr[arr[i]] == arr[i])
                return 0;

            swap(&arr[i], &arr[arr[i]]);
        } while(arr[i] != i);
    }

    return 1;
}
