#include <stdio.h>
#include <string.h>

#include "black_box.c"

#define N 4

void sort_mat(int a[][N]);
int checkLang(char* sentence);
int MaxRelative(int* arr, int n);
void sort_arr(int a[], int n);

int main() {
    printf("\n\n");

    char str[] = "pmtwxn9mtn pbr-%$jpcuwfRjvcufgxn$pbL";
    printf("Should return 1: %d\n", checkLang(str));
    
    char str2[] = "pmtwtn4mtn pbr-jfcuwfjrRjvcu3fggxn$pbL";
    printf("Should return 0: %d\n", checkLang(str2));

    int arr[] = { 24, 28, 22, 4, 6,7,8,6,5,11,10,21,9,4,13 };
    printf("Should return 23: %d\n", MaxRelative(arr, sizeof(arr) / sizeof(arr[0])));

    int arr2[] = { 0,1,0,0,1,2,1,2,0,2,1,0,0 };
    sort_arr(arr2, sizeof(arr2) / sizeof(arr2[0]));
    printf("Should return sorted array: ");
    print_array(arr2, sizeof(arr2) / sizeof(arr2[0]));
    
    int a[][N] = {
        { 2, 14, 16, 8 },
        { 2, -7, 17, 7 },
        { -1, -4, -7, -9 },
        { 0, 15, 3, 20 }
    };

    printf("Source matrix: \n");
    print_matrix((int*) a, N, N);
    
    sort_mat(a);

    printf("Output matrix: \n");
    print_matrix((int*) a, N, N);
    return 0;
}

int checkWord(char* word) {
    int seen[26] = { 0 };
    int i, word_len = strlen(word);

    for (i = 0; i < word_len; i++) {
        seen[word[i] - 'a']++;
        if (seen[word[i] - 'a'] > 1)
            return 0;
    }

    return 1;
}

int checkLang(char* sentence) {
    int i, len = strlen(sentence), cursor = 0;
    char backup;

    for (i = 0; i < len; i++) {
        if (sentence[i] - 'a' < 0 || sentence[i] - 'a' > 25) {
            backup = sentence[i];
            sentence[i] = '\0';

            if (!checkWord(&sentence[cursor])) {
                sentence[i] = backup;
                return 0;
            }

            sentence[i] = backup;
            cursor = i+1;
        }
    }

    return 1;
}

int MaxRelative(int* arr, int n) {
    int max = 0, current_calc;
    if (n < 3)
        return 0;
    
    max = MaxRelative(arr+1, n-1);
    current_calc = (arr[1] - arr[0]) + (arr[1] - arr[2]);
    return current_calc > max ? current_calc : max;
}

void sort_arr(int a[], int n) {
    int i, count_0 = 0, count_1 = 0;
    for (i = 0; i < n; i++) {
        !a[i] && count_0++;
        a[i] == 1 && count_1++;
    }

    for (i = 0; i < n; i++) {
        if (count_0) {
            a[i] = 0;
            count_0 --;
        } else if (count_1) {
            a[i] = 1;
            count_1 --;
        } else {
            a[i] = 2;
        }
    }
}

void sort_mat(int a[][N]) {
    quick_sort((int*) a, 0, (N*N)-1);
}