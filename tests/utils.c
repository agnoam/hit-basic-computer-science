#include <stdio.h>
#include <io.h>

/* 
    This function redirects the `stdin` and or the `stdout` of the program to specifc files
    
    Param input_filename (const char *): What file to redirect into the stdin
    Param redirect_output (format 0/1): Wheter to redirect the stdout as well
*/
int redirect_io(const char *input_filename, int redirect_output) {
    if (access(input_filename, F_OK) == 0) {
        // Redirect input and output to simulate and capture the behavior of the function
        freopen(input_filename, "r", stdin);  // Open file for reading
    }

    if (redirect_output)
        freopen("current_output.txt", "w", stdout);  // Redirect output to a file
}

void stop_io_redirection(int original_stdout) {
    // Closing and flushing the files
    fflush(stdin);
    fclose(stdin);

    fflush(stdout);
    fclose(stdout);
}