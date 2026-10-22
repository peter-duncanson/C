/* =============================================================================
 * C Programming - A Modern Approach - K.N. King
 * Chapter 15 - Writing Large Programs
 * Exercises
 * ========================================================================== */

/*
1.  Section 15.1 listed several advantages of dividing a program into multiple
    source files.
    (a) Describe several other advantages.
        The program is much easier to maintain, as control blocks and
        functionality are each atomized in their own files. So we can make
        changes to one aspect of how the program works, with the other parts
        viewing it as a black box of sorts where all that matters are input
        and return types for each module.
        Another advantage is when making changes, the entire program doesn't
        have to be recompiled. We can recompile the source files we made
        changes in, then re-link everything.
    (b) Describe some disadvantages.
        For smaller programs, it can create needless complexity.

2.  Which of the following should not be put in a header file? Why not?
    (a) Function prototypes
        This is good
    (b) Function definitions
        This is not good, function definitions in a header file will cause
        issues when object files are creates and the linker has to deal with
        multiple definitions of the functions, since they will be defined in
        every source file that includes the header, instead of defined in a
        single source file and referenced by including the header containing
        their prototypes.
    (c) Macro definitions
        This is good
    (d) Type definitions
        This is good

3.  We saw that writing #include <file> instead of #include "file" may not work
    if file is one that we've written. Would there be any problem with writing
    #include "file" instead of #include <file> if the file is a system header?
    Not really, but kind of, if the compiler doesn't find a "file" then it will
    go looking for it in other implimentation defined places, like where
    standard library headers live. So something like #include "stdio.h"
    technically works, however it could cause problems if we somehow write a
    header that somehow has the same name as a stadnard header.

4   Assume the debug.h is a header file with the following contents:

    #ifdef DEBUG
    #define PRINT_DEBUG(n) printf("Value of  " #n ": %d\n", n);
    #else
    #define PRINT_DEBUG(n)
    #endif

    Let testdebug.c be the following source file:

    #include <stdio.h>

    #define DEBUG
    #include "debug.h"


    int main(void)
    {
        int i = 1, j = 2, k = 3;

    #ifdef DEBUG
        printf("Output if DEBUG is defined:\n");
    #else
        printf("Output if DEBUG is not defined:\n");
    #endif
        
        PRINT_DEBUG(i);
        PRINT_DEBUG(j);
        PRINT_DEBUG(k);
        PRINT_DEBUG(i + j);
        PRINT_DEBUG(2 * i + j - k);

        return 0;
    }
    
    (a) What is the output when the program is executed?
        Output if DEGUG is defined:
        Value of i: 1
        Value of j: 2
        Value of k: 3
        Value of i + j: 3
        Value of 2 * i + j - k: 1
    (b) What is the output if the #define directive is removed from testdebug.c?
        Output if DEBUG is not defined:
    (c) Exaplin why the output if different in parts (a) and (b)
        DEBUG is not defined in part (b), so PRINT_DEBUG gets left empty.
    (d) Is it necessary for the DEBUG macro to be defined before debug.h is
        included in order for PRINT_DEBUG to have the desired effect? Justify
        your answer.
        Yes! When debug.h is included, it is inserted starting on line line
        with the #include directive, it won't retroactively look for a 
        definition of debug

5.  Suppose that a program consists of three source files - main.c, f1.c, and
    f2.c - plus two header files, f1.h and f2.h. All three source files include
    f1.h but only f1.c and f2.c include f2.h. Write a makefile for this program,
    assuming that the compiler is gcc and that the executable file is to be
    named demo.

    demo: main.o f1.o f2.o
        gcc -o demo main.o f1.o f2.o

    main.o: main.c f1.h
        gcc -c main.c

    f1.o: f1.c f1.h f2.h
        gcc -c f1.c

    f2.o: f2.c f2.h f1.h
        gcc -c f2.c

6.  The following questions refer to the program described in exercise 5.
    (a) Which files need to be compiled when the program is built for the first
        time?
        main.c, f1.c, f2.c
    (b) If f1.c is changed after the program has been built, which files need to
        be recompiled?
        f1.c, then demo must be relinked
    (c) If f1.h is changed after the program has been built, which files need to
        be recompiled?
        all of them
    (d) If f2.h is changed after the program has been built, which files need to
        be recompiled?
        f1.c and f2.c
*/
