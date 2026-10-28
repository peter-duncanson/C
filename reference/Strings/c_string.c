#include "c_string.h"

String new_string(const char *s, size_t len)
{
    String *s = malloc(sizeof(String));
    if (s == NULL) {
        fprintf(stderr, "Malloc returned null pointer.");
        exit(1);
    }

    s->data = malloc(sizeof(char) * len);
    if (s->data == NULL) {
        fprintf(stderr, "Malloc returned null pointer.");
        exit(1);
    }
    s->size = len
    
    return 0;
}
