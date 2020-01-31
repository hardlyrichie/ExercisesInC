# Exercise 1 Answers

### Basics of compilation

8.
```
    gcc -ansi -pedantic -Wall cards.c
```
`-ansi`: support all ANSI standard C programs and turns off certain features of GCC that are incompatible with ANSI C  

`-pedantic`: issue all the warnings demanded by strict ANSI C and reject all programs that use forbidden extensions

`-Wall`: all of the `-W` options combined. This enables all the warnings about constructions 

### Optimization

1. 
```
    subq    $16, %rsp
    movl    $5, -4(%rbp)
```

2. When using the optimization flag the assembly language output changes as the code outside gets more detailed with code like `.text.unlikely,"ax",@progbits` and the code in `main` becomes more condenced and shorter.

3. Now when printing x, the assembly code calls `printf` when unoptimized and `__printf_chk` when optimized instead of calling `puts` as done previously.

4. `x` and `y` when optimized are defined in less steps with what looks like an `xorl` command instead of `addl` in the `main` function. Optimization, therefore, works by replacing functions and commands with more succient operations when brought to assembly reducing the number of operations needed for the same logic.