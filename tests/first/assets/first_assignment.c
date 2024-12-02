#include <stdio.h>
#include <math.h>
#include <limits.h>

// Functions declarations
int q_one(int n);
int q_two(long n);
int q_three(int k);
int q_four(int n);


// Q1: Calculates the sum of the first n numbers consisting of just 1s
int q_one(int n) {
    int acc = 0, sum = 0, i;
    for (i = 0; i < n; i++) {
        acc = (acc * 10) + 1;
        sum += acc;
    }

    return sum;
}

// Q2: Given a positive number, calculate the sum of its minimum and maximum digits
int q_two(long n) {
    int dig = n % 10, min = dig, max = dig;

    while (n > 0) {
        dig = n % 10;
        if (dig < min) 
            min = dig;
        else if (dig > max) 
            max = dig;

        n /= 10;
    }

    return max + min;
}

/* 
    Q3: Given a threshold k, repeatedly read numbers from input, 
    calculating the sum of the current minimum and the current input. If the sum exceeds k, 
    stop reading, and indicate (1) if the last input was not -1 or (0) otherwise
*/
int q_three(int k) {
    int input, min = -1, sum = INT_MAX;

    do {
        printf("Enter number: ");
        scanf("%d", &input);

        if ((input < min) || min == -1) {
            min = input;
            continue;
        }

        sum = input + min;
    } while (input != -1 && sum > k);
    
    // Else the loop will break because of the sum
    return input != -1;
}

/*  
    Q4: Given an integer, determine if it is a palindrome. 
    A palindrome is a number that reads the same backward as forward. 
*/
int q_four(int n) {
    int original, mirror_num = 0;
    original = n;

    while (n > 0) {
        mirror_num *= 10;
        mirror_num += n % 10;
        
        n /= 10;
    }

    // In case `n > 0` it means the loop broke before it reaches the end
    return mirror_num == original;
}
