/* An implementation of tee small tool

Tee command reads standard input and writes it to both standard 
output and one or more files.

-a
    append to the given FILEs, do not overwrite

Richard Gao
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    char ch;
    char *mode = "w";
    while ((ch = getopt(argc, argv, "a")) != EOF) {
        // -a tag, appends to file flag
        if (ch == 'a') {
            mode = "a";
        }
    }
    argc -= optind;
    argv += optind;

    // Open up files
    FILE *files[argc];
    for (int i = 0; i < argc; i++) {
        files[i] = fopen(argv[i], mode);
    }

    // Read from stdin until EOF char
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, stdin) != -1) {
        // Write to each output
        for (int i = 0; i < argc; i++) {
            fprintf(files[i], "%s", line);
        }
        printf("%s", line);
    }
    
    free(line);
    for (int i = 0; i < argc; i++) {
        fclose(files[i]);
    }

    return 0;
}

/* Reflection
3. Opening and Writing to Files worked well as it was pretty
straightforward from HeadFirstC. However, what was more difficult
was continuously reading in a line without ending the program and
allocating the appropriate memory for this buffer. To do this
I had to research and find the getline() function. For next time
I will consult google earlier in the process to see if something
can make my life easier.

5. The professional code has warning statements and other command
line arguments.
*/