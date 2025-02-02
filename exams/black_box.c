/**
    Searches for a target value in a sorted array using the Binary Search algorithm.

    @param array Pointer to the sorted array.
    @param size Size of the array.
    @param target The value to be searched for.

    @returns If the target is found, the function returns its index in the array. Otherwise, it returns `-1`.
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
 * Performs a binary search to find the leftmost (first) occurrence of a target value in a sorted array.
 * 
 * @param array Pointer to the sorted integer array.
 * @param size The number of elements in the array.
 * @param target The value to search for.
 * 
 * @return The index of the leftmost occurrence of the target in the array, or -1 if not found.
 */
int binary_search_left(int* array, int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // To prevent potential overflow
        if (array[mid] == target && array[mid-1] != target) {
            return mid;
        } else if (array[mid] >= target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

/**
 * Performs a binary search to find the rightmost (last) occurrence of a target value in a sorted array.
 * 
 * @param array Pointer to the sorted integer array.
 * @param size The number of elements in the array.
 * @param target The value to search for.
 * 
 * @return The index of the rightmost occurrence of the target in the array, or -1 if not found.
 */
int binary_search_right(int* array, int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // To prevent potential overflow
        if (array[mid] == target && array[mid+1] != target) {
            return mid;
        } else if (array[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

/**
    Prints an array of integers

    @param arr An int pointer to the first element of the array
    @param n The length of the given array
*/
void print_array(int* arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++)
        printf(i == n-1 ? "%d" : "%d, ", arr[i]);
    printf("]\n");
}

/**
    Swaps between two integers. 

    @param a First pointer to to swap
    @param b Second pointer to swap
*/
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
    Partitions the array around a pivot element.

    @param arr Pointer to the array to be partitioned.
    @param low Starting index of the array segment.
    @param high Ending index of the array segment.

    @returns The partition index (`j`), where all elements to the left of `j` 
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

    @param arr Pointer to the array to be sorted.
    @param low Starting index of the array segment.
    @param high Ending index of the array segment.
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
