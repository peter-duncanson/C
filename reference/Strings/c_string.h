#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


    typedef struct str {
    const char *data;
    size_t size;
} String;

String new_string(cosnt char *s, size_t size);

String make_slice(const char *s, size_t start, size_t end);

