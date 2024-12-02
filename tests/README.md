This folder contains test files for each assignment. 
In order to test your file, you should copy your assignment file into `/tests/first/assets/first_assignment.c` and ommit the `int main()` function.

For example:
1. Check your assignment file have functions as described in the `test.c` file [example test file](/tests/first/test.c)
2. Copy your `c program` into the appropriate directory into the path `tests/<assignment_name>/assets/<file_name>.c`
3. Run the test using `./test.exe` and in case the test run successfully, no errors will thrown.

Or you can use the copy_assignment.sh script to copy and remove the `main()` function.
Example: `cd ./tests && ./copy_assignment.sh <your_assignment_file> ./first/assets/first_assignment.c`