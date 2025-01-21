#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int findCommonDigit(unsigned long long n1, unsigned long long n2);
int moveDuplicatesV1(int* arr, int n);

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

        // case 2:
        //     printf("Enter number to return the count of ones in it's binary representation: ");
        //     scanf("%d", &n);
        //     printf("Number of 1s is: %d", number_of_bin_ones(n));
        //     break;

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
        `a` - First pointer to to swap (could not be null)
        `b` - Second pointer to swap (could not be null)
*/
void swap(int *a, int *b) {
    if (!a || !b) {
        printf("Can not swap with null");
        return;
    }

    *b += *a;
    *a = *b - *a;
    *b -= *a;
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
    Moves the duplicates to the end of the array,
    while maintaining the order of the unique values in the array.

    Parameters:
        `arr`: Pointer to the first element of the array
        `n`: The length of the array

    Returns:
        The count of unique elements or `-1` in case of an error.
*/
int moveDuplicatesV1(int* arr, int n) {
    int i, min, max, unique_count = 0;
    int replace_index = -1;
    range_of_array(arr, n, &min, &max);

    int* unique_arr = (int*) calloc((max-min)+1 +1, sizeof(int));
    if (!unique_arr) {
        printf("Memory allocation failed\n");
        return -1;
    }

    // Generates 1 hot encoded array ("is unique")
    for (i = 0; i < n; i++) {
        // Starting the count from the minimum value
        int val = arr[i];
        if (!unique_arr[val]) {
            unique_arr[val] = 1;
            unique_count++;
        }
    }

    for (i = 0; i < n; i++) {
        if (replace_index == -1 && !unique_arr[arr[i]]) {
            replace_index = i;
        } else if (replace_index != -1 && unique_arr[arr[i]]) {
            unique_arr[arr[i]] = 0;
            swap(&arr[i], &arr[replace_index]);
            replace_index++;
            
            // Finding the next duplicate element whitin the subarray
            for (int j = replace_index; j < i; i++) {
                if (!unique_arr[arr[j]])
                    break;
                
                replace_index = j;
            }
        } 
        
        if (unique_arr[arr[i]]) {
            // Marking the number as duplicate (because already read once)
            unique_arr[arr[i]] = 0;
        }
    }

    return unique_count;
}