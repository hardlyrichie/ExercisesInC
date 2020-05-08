/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>

/*
It doesn't seem that parent and child processes share any global, heap, or stack
variables. I defined them all in the parent, changed the variables in the child
processes, and printed out the variables again in the parent after all the child
processes have died. However, the values haven't been updated. Therefore, they
are not the same.
*/

// errno is an external global variable that contains
// error information
extern int errno;
int global;


// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
    struct timeval tv[1];

    gettimeofday(tv, NULL);
    return tv->tv_sec + tv->tv_usec / 1e6;
}


void child_code(int i)
{
    sleep(i);
    printf("Hello from child %d.\n", i);
}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[])
{
    int status;
    pid_t pid;
    double start, stop;
    int i, num_children;
    int *heap = malloc(sizeof(int));
    int stack;
    global = 1;
    *heap = 2;
    stack = 3;

    // the first command-line argument is the name of the executable.
    // if there is a second, it is the number of children to create.
    if (argc == 2) {
        num_children = atoi(argv[1]);
    } else {
        num_children = 1;
    }

    // get the start time
    start = get_seconds();

    for (i=0; i<num_children; i++) {

        // create a child process
        printf("Creating child %d.\n", i);
        pid = fork();

        /* check for an error */
        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        /* see if we're the parent or the child */
        if (pid == 0) {
            child_code(i);
            global++;
            *heap += 1;
            stack++;    
            printf("Child Global: %i Global address: %p\n", global, &global);
            printf("Child Heap: %i Heap address: %p\n", *heap, &heap);
            printf("Child Stack: %i Stack address: %p\n", stack, &stack);
            exit(i);
        }
    }

    /* parent continues */
    printf("Hello from the parent.\n");
    printf("Parent Global: %i Global address: %p\n", global, &global);
    printf("Parent Heap: %i Heap address: %p\n", *heap, &heap);
    printf("Parent Stack: %i Stack address: %p\n", stack, &stack);

    for (i=0; i<num_children; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        // check the exit status of the child
        status = WEXITSTATUS(status);
        printf("Child %d exited with error code %d.\n", pid, status);
    }

    printf("Parent Global: %i Global address: %p\n", global, &global);
    printf("Parent Heap: %i Heap address: %p\n", *heap, &heap);
    printf("Parent Stack: %i Stack address: %p\n", stack, &stack);

    // compute the elapsed time
    stop = get_seconds();
    printf("Elapsed time = %f seconds.\n", stop - start);

    exit(0);
}
