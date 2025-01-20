#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int findCommonDigit(unsigned long long n1, unsigned long long n2);

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

/*
    Finds the common digits between `n1` and `n2`, 
    
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