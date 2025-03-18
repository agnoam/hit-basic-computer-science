[This is the prompt](#prompt-show-as-text-to-copy) used for the [GPT code analysis](https://chatgpt.com/share/67676b12-f2f8-800d-a30b-e8a4c0c32d7c)

# My responses to GPT solutions:
According to the chat provided above, GPT reviewed my code and helped me to find two problems in my implementation in the `diff()` and `bigger_rev()` functions.

<details>
    <summary>Relevant code</summary>

This section includes only the updated code that relevant to GPT's review. <br/> Please see the full code in the provided `.c` file.

```c
int diff(int num) {
    int digit = num % 10;
    if (num == 0)
        return 0;

    digit = !(digit % 2) ? digit : -digit;
    return digit + diff(num/10);
}

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
```
</details>

## `diff()` function:
The problem was a logical bug, that made the function return wrong values when received numbers with odd digits. Thanks to the review, I got a lead to a simpler solution, which implemented in the new code. (See the full discussion in the link)

## `big_rev()` function:
The problem was a logical bug, which caused because lacking information in the question declaration: **Whether the input list can receive negative integers**. Thanks to GPT, which tried to clarify this edge case. I decided to change the code to support this scenario, which forced me to use the `limits.h` include.

# Prompt (show as text to copy):
<details>
    <summary>Prompt as text</summary><br/>

Check the provided code below, suggest code optimizations, and search for possible logical bugs. Ignore `main()` function, and input validation checks in your review.
FYI: All function implementations should be recursive, and array usage is prohibited.

```c
<second_assignment.c> as plain text here
```
</details>