#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    struct node *next;
} Node;

void add_task(Node **head, int task_id)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->id = task_id;
    new_node->next = *head;
    *head = new_node;
}

void print_tasks(Node *head)
{
    while (head) {
        printf("TASK ID: %d\n", head->id);
        head = head->next;
    }
}

int main(void)
{
    Node *task_list = NULL;
    add_task(&task_list, 1);
    add_task(&task_list, 2);
    add_task(&task_list, 3);
    add_task(&task_list, 4);
    print_tasks(task_list);

    return 0;
}
