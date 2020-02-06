/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void anotherOne() {
    int var3 = 10;
    printf ("Address of var3 is %p\n", &var3);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    char *s = "Hello, World";
    void *foo = malloc(128);

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);
    printf ("foo points to %p\n", foo);

    anotherOne();

    void *bar = malloc(20);
    void *baz = malloc(20);
    printf ("bar points to %p\n", bar);
    printf ("baz points to %p\n", baz);

    return 0;
}
