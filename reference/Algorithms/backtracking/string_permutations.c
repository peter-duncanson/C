/*
Given a string s, find all permutations of the given string. 
Return the permutations in lexicographically non-decreasing order.

Input:  s = "ABC"
Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]

Input: s = "XY"
Output: ["XY", "YX"]

Input: s = "AAA"
Output: "AAA", "AAA", "AAA", "AAA", "AAA", "AAA"
*/
#include <stdio.h>
#include <string.h>

const char **string_permutations(const char *s);
const char *recurse();
size_t factorial(size_t n);

int main(void)
{
    const char *s = "ABC";
    const char **permutations = string_permutations(s);
    // for (const char *p = permutations; p )
    return 0;
}

const char **string_permutations(const char *s)
{
    size_t n_permute = factorial(strlen(s));

    permutations 
    
}

const char *recurse(const char *s, char *result, int index)
{
    if (index == strlen(s))
        return 
}


size_t factorial(size_t n)
{
    return (n <= 1) ? 1 : n * factorial(n - 1);
}
