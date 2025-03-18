#include <stdio.h>
#include <limits.h>

// Functions declarations
void decimal_to_binary(int num);
int number_of_bin_ones(int num);
int diff(int num);
int bigger_rev(int n);

int main() {
    int q_number, n;

    printf("Enter the number of question to run (1-4): ");
    scanf("%d", &q_number);

    switch (q_number) {
        case 1:
            printf("Enter positive decimal number to convert into binary: ");
            scanf("%d", &n);
            decimal_to_binary(n);
            break;

        case 2:
            printf("Enter number to return the count of ones in it's binary representation: ");
            scanf("%d", &n);
            printf("Number of 1s is: %d", number_of_bin_ones(n));
            break;

        case 3:
            printf("Enter a decimal positive number to calculate the delta between the even digits and odd digits sums: ");
            scanf("%d", &n);
            printf("The delta is: %d", diff(n));
            break;

        case 4:
            printf("Enter the length of the input list: ");
            scanf("%d", &n);
            bigger_rev(n);
            break;

        default:
            printf("Invalid question number");
            return 1;
    }

    return 0;
}

/*
    Recursive function that prints given decimal number as binary
    Param: `num` - Positive decimal number

    Tests (arg -> output):
        10 -> 1010
        5 -> 101
        13 -> 1101
*/
void decimal_to_binary(int num) {
    if (num <= 1) {
        printf("%d", num);
        return;
    }

    decimal_to_binary(num / 2);
    printf("%d", num % 2);
}

/*
    Recursive function that counts the `1` digits exists in a binary number,
    which calculated from a given positive decimal number.

    Param: `num` - Positive decimal number

    Tests (arg -> output):
        0 -> 0
        1 -> 1
        5 -> 2
        6 -> 2
        10 -> 2
        13 -> 3
*/
int number_of_bin_ones(int num) {
    if (num <= 1)
        return num;
    return num % 2 + number_of_bin_ones(num / 2);
}

/*
    Recursive function that returns the delta 
    of the even numbers sum and the odd numbers.

    Param: `num` - Positive decimal number

    Tests (arg -> output):
        1234567 -> -4
        521376 -> -8
        12 -> 1
        19 -> -10
*/
int diff(int num) {
    int digit = num % 10;
    if (num == 0)
        return 0;

    digit = !(digit % 2) ? digit : -digit;
    return digit + diff(num/10);
}

/*
    Recursive function that receiving the n positive numbers.
    And printing all the numbers which greater than all of the numbers entered after them.

    Param: `n` - The length of the sequence to receive

    Tests (arg -> (input) -> [output]):
        8 -> (7, 13, 2, 1, 9, 4, 2, 3) -> [3, 4, 9, 13]
        2 -> (1, 7) -> [7]
        5 -> (5, 4, 3, 2, 1) -> [1, 2, 3, 4, 5]
        3 -> (0, -6, -3) -> [-3, 0]
*/
int bigger_rev(int n) {
    int input, max_num;
    if (n == 0)
        return INT_MIN;
    
    printf("Write a number: ");
    scanf("%d", &input);

    max_num = bigger_rev(n - 1);
    if (input > max_num) {
        printf("%d, ", input);
        max_num = input;
    }
    
    return max_num;
}
