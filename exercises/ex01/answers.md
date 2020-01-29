# Exercise 1 Answers

### Basics of compilation

8.
```
    gcc -ansi -pedantic -Wall cards.c
```
`-ansi`: support all ANSI standard C programs and turns off certain features of GCC that are incompatible with ANSI C  

`-pedantic`: issue all the warnings demanded by strict ANSI C and reject all programs that use forbidden extensions

`-Wall`: all of the `-W` options combined. This enables all the warnings about constructions 