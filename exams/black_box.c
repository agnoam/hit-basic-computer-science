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
