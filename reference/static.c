/*
 * In C, functions are global, so functions defined in one file can be used in another file
 * In lib.c we can define a function that outputs hello, then in main.c we can declare the
 * function signature and then use it in the other file as long as they are compiled together
 *
 * OK.....
 *
 * The static keyword is used to limit the scope of the function to the file where it is defined
 * Used to achieve information hiding
 * */
