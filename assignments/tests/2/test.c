#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../utils.c"
#include "../copied_src_code/second_assignment.c"

void test_q_one() {
    redirect_io("assets/input_files/q1/(8)=4.txt", 0);
    assert(q_one(8) == 4);
    
    redirect_io("assets/input_files/q1/(1)=1.txt", 0);
    assert(q_one(1) == 1);

    redirect_io("assets/input_files/q1/(30)=7.txt", 0);
    assert(q_one(30) == 7);
}

// void test_q_two() {
//     redirect_io("", 1);
//     q_two(52);

//     assert(strstr("9") != NULL);
//     assert(strstr("5") != NULL);
// }

void test_q_three() {
    // Test perfect powers
    assert(q_three(0) == 1);
    assert(q_three(1) == 1);
    assert(q_three(2) == 1);
    assert(q_three(153) == 1);
    assert(q_three(1634) == 1);

    // Test numbers that are not perfect powers
    assert(q_three(123) == 0);  // Not a perfect power
    assert(q_three(777) == 0);   // Not a perfect power
    assert(q_three(12) == 0);   // Not a perfect power
}

int main() {
    printf("Starting to run tests...\n");

    test_q_one();
    printf("q_one tests passed\n");
    // test_q_two();
    // printf("q_two tests passed.\n");
    test_q_three();
    printf("q_three tests passed.\n");

    return 0;
}