// #include "linked_stack.h"
#include "cont_stack.h"

int main(void)
{
    puts("Welcome to the Stack!");
    size_t stack_capacity = 0;
    size_t element_size = 0;
    size_t pop_value = 0;
    int user_input;
    Stack *s = NULL;

    while (true)
    {
        printf("Enter a capacity for your stack.\n> ");
        scanf("%d", &stack_capacity);
        if (stack_capacity > MAXSTACK)
            printf("Enter a number less than %d.\n", MAXSTACK);
        else break;
    }

    while (true)
    {
        printf("Enter a size in bytes for the elements.\n> ");
        scanf("%lu", &element_size);

        switch (element_size)
        {
            case 1:
                s = stack_create(stack_capacity, element_size);
                printf("Stack succesfully created to store %lu char.\n", stack_capacity);
                break;
            case 2:
            case 4:
                s = stack_create(stack_capacity, element_size);
                printf("Stack succesfully created to store %lu int.\n", stack_capacity);
                break;
            default:
                puts("Invalid size entered. Please try again.");
                break;
        }
        if (s != NULL) break;
    }

    for (;;)
    {
        puts("[a] push\t[b] pop\t[c] peek\t[p] print [v] view popped [q] quit");
        while ((user_input = getchar()) != '\n')
        {
            switch (user_input)
            {
                case 'a': // push
                    size_t push_value;
                    printf("Value to push:\n> ");
                    scanf("%lu", &push_value);
                    push(s, &push_value);
                    break;

                case 'b': // pop
                    pop(s, &pop_value);
                    break;
                case 'c': // peek
                    peek(s, &pop_value);
                    break;
                case 'p': // print
                    stack_print(s);
                    break;
                case 'v': // view popped
                    printf("Popped value: %lu\n", pop_value);
                    break;
                case 'q': // quit
                    stack_destroy(s);
                    puts("Stack succesfully destroyed, exiting.");
                    exit(0);
            }
        }
    }
    // should not happen
    return 1;
}
