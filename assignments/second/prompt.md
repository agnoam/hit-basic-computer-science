[This is the prompt](#prompt-show-as-text-to-copy) used for the [GPT code analysis](https://chatgpt.com/share/674e171e-4a40-800d-849e-9c10ef50d6be)

# My responses to GPT solutions:
As GPT's response suggests, It did not enhance the runtime efficency of the answers of 1-3.

But, GPT helped me to optimize the runtime complexity of my answer to question 4. <br/>
My original answer was as follows:

```c
/* 
    Q4: Find all amicable numbers within given range
    Param: `n` - The range of numbers to search within
*/
int sum_devisors(int n) {
    int i, sum = 1; // 1 is always a divisor (except for n=1)
    for (i = 2; i < n; i++) {
        if (!(n % i))
            sum += i;
    }

    return sum;
}

void q_four(int n) {
    int i, sum_of_a, sum_of_b;

    // Staring the loop from 2 because the amicable numbers are defined for integers greater than 1
    for (i = 2; i < n; i++) {
        sum_of_a = sum_devisors(i);
        
        // Practicly skipping the duplicates
        if (sum_of_a == i) 
            continue;

        sum_of_b = sum_devisors(sum_of_a);
        sum_of_b == i && printf("Amicable numbers: (%d, %d)\n", i, sum_of_a);
    }
}
```

But, as this code suggests. The runtime complexity of this implementation is $O(n^2)$ which is not the most optimal.

So, after consulting GPT I came up with this solution:
```c
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
```

Which improved the overall runtime complexity to $O(n\sqrt(n))$.

# Prompt (show as text to copy):
<details>
    <summary>Prompt as text</summary><br/>

Check each function that starts with q_* in the provided c code below, suggest enhancements for more efficient code, and find possible logical bugs. ignore validation checks in your review. 

```
<second_assignment.c> as plain text here
```
</details>