#include <stdio.h>
#include <assert.h>

#include "../copied_src_code/first_assignment.c"

void test_q_one() {
    assert(q_one(6) == 123456); // Example from assets

    // LLM generated tests
    assert(q_one(1) == 1);
    assert(q_one(2) == 12);
    assert(q_one(5) == 12345);
}

void test_q_two() {
    assert(q_two(32723856) == 10); // Example from assets

    // LLM generated tests
    assert(q_two(12345) == 6);
    assert(q_two(6543210) == 6);
    assert(q_two(77777) == 14);
}

// Q_three avoided due to `scanf`

void test_q_four() {
    assert(q_four(3443) == 1); // Example from assets
    
    // LLM generated tests
    assert(q_four(1221) == 1);
    assert(q_four(22) == 1);
    assert(q_four(1222) == 0);
    assert(q_four(12) == 0);
}


int main() {
    test_q_one();
    printf("q_one tests passed\n");
    test_q_two();
    printf("q_two tests passed\n");
    test_q_four();
    printf("q_four tests passed\n");
    
    return 0;
}