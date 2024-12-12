#include <stdio.h>
#include <math.h>

// Functions declarations
int q_one(int n);
void q_two(int n);
int q_three(int n);
void q_four(int n);

int main() {
    int q_number, n;

    printf("Enter the number of question to run (1-4): ");
    scanf("%d", &q_number);

    switch (q_number) {
        case 1:
            printf("Enter the length of the list to find the longest sub-sequence in it: ");
            scanf("%d", &n);
            printf("The sum is: %d", q_one(n));
            break;

        case 2:
            printf("Enter number to calculate the possible values for n (3x + 5y = n): ");
            scanf("%d", &n);
            q_two(n);
            break;

        case 3:
            printf("Write the number to check wheter it narcissistic number: ");
            scanf("%d", &n);
            if (q_three(n))
                printf("YES");
            else
                printf("NO");
            break;

        case 4:
            printf("Enter the max number to search the amicable numbers until: ");
            scanf("%d", &n);
            q_four(n);
            break;

        default:
            printf("Invalid question number");
            return 1;
    }

    return 0;
}

// Q1: Finds the longest sub sequence of the same number (1/0)
int q_one(int n) {
    int last_number = -1, current_number = -1, sub_length = 0, max_length = 1, starting_index = 1, i;
    for (i = 0; i < n; i++) {
        scanf("%d", &current_number);
        
        if (last_number == current_number)
            sub_length++;
        else
            sub_length = 0;

        if (sub_length > max_length) {
            max_length = sub_length;
            starting_index = (i - sub_length) + 1;
        }
        
        last_number = current_number;
    }

    return starting_index;
}

/*
    Q2: Calculates the possible values for the equation (3x + 5y = n)
    Param: `n` - Number to calculate (should be > 7)
*/
void q_two(int n) {
    int x, y, i, diff, best_x = 0, best_y = 0, min_diff = n;
    for (i = 1; i <= (n / 5); i++) {
        int calc = n - (5*i);
        x = calc / 3;

        if (calc % 3 == 0 && x) {
            y = i;
            diff = abs(y - x); 

            if (diff < min_diff) {
                min_diff = diff;
                best_x = x;
                best_y = y;
            }
        }
    }

    if (!best_x || !best_y) {
        printf("No solution found.\a");
    } else {
        printf("(%d, %d)", best_x, best_y);
    }
}

/*
    Q3: Check whether a given number is a "perfect power" (amstrong number / narcissistic number)
    Param: `n` - The number to check
*/
int q_three(int n) {
    int sum = 0, count = 0, original = n;
    
    while (n > 0) {
        count ++;
        n /= 10;
    }

    n = original;
    while(n > 0) {
        sum += pow(n % 10, count);
        n /= 10;
    }

    return sum == original;
}

/* 
    Q4: Find all amicable numbers within given range
    Param: `n` - The range of numbers to search within
*/
int sum_devisors(int n) {
    int i, sum = 1; // 1 is always a divisor (except for n=1)
    for (i = 2; i * i <= n; i++) {
        if (!(n % i)) {
            sum += i;
            if (i != n / i) sum += n / i; // Avoid double-counting the square root
        }
    }

    return sum;
}

void q_four(int n) {
    int i, sum_of_a, sum_of_b;

    // Staring the loop from 2 because the amicable numbers are defined for integers greater than 1
    for (i = 2; i < n; i++) {
        sum_of_a = sum_devisors(i);
        
        // Practicly skipping the duplicates
        if (sum_of_a <= i || sum_of_a >= n) 
            continue;

        sum_of_b = sum_devisors(sum_of_a);
        sum_of_b == i && printf("Amicable numbers: (%d, %d)\n", i, sum_of_a);
    }
}