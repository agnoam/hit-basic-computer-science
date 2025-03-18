This folder contains unit-test files for each assignment. 
In order to unit-test your own files, you should copy your assignment file into `/tests/copied_assignment/first_assignment.c` and ommit the `int main()` function.

For example:
1. Check your assignment file have functions as described in the `first_assignment.c` file [example test file](./copied_src_code/first_assignment.c) (This file is not indeed the latest version of the code, so it advised to copy all of the assignments again)
2. Copy your `c program` into the appropriate directory into the path `tests/copied_src_code/<file_name>.c`
3. Run the test using `./test.exe` and in case the test run successfully, no errors will thrown.

Or you can use the copy_assignment.sh script to copy and remove the `main()` function.
You should run this oommand from the root directory of the repository

You should check the what name the unit-test is programmed to. you can see it by the `#include ...<assignment>.c` line in the top of the test-file.
Example: `./tests/copy_assignment.sh <your_assignment_file_path_and_name>.c ./tests/copied_src_code/<relevant_assignment_test>.c`
