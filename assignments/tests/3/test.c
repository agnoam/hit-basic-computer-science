#include <stdio.h>
#include <assert.h>

#include "../copied_src_code/third_assignment.c"

void test_q_two() {
    assert(number_of_bin_ones(0) == 0);
    assert(number_of_bin_ones(1) == 1);
    assert(number_of_bin_ones(5) == 2);
    assert(number_of_bin_ones(6) == 2);
    assert(number_of_bin_ones(10) == 2);
    assert(number_of_bin_ones(13) == 3);
}

void test_q_three() {
    assert(diff(1234567) == -4);
    assert(diff(521376) == -8);
    assert(diff(12) == 1);
    assert(diff(19) == -10);
}

int main() {
    printf("Starting to run tests...\n");

    test_q_two();
    printf("q_two tests passed.\n");
    test_q_three();
    printf("q_three tests passed.\n");

    return 0;
}

