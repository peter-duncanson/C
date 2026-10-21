#include <stdio.h>

int get_input_len() {
    int len = 0;

    printf("Enter a message: ");
    while (getchar() != '\n') {
        len++;
    }

    return len;
}

int main() {
    int len = get_input_len();
    printf("The message was %d character(s) long\n", len);
}

