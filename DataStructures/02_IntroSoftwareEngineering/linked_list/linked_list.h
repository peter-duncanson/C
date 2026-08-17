#define MAXLIST 300

typedef char ListEntry;

typedef struct node
{
    int count;
    ListEntry value;
    ListEntry *next;
} Node;

void list_create(Node *);
void list_clear(Node *);
bool list_empty(const Node *);
bool list_full(const Node *);
int list_size(const Node *);
void list_add(NodeEntry, Node *);
void list_traverse(Node *, void(*)(NodeEntry));
void list_copy(Node *, const Node *);
void copy_list(Node *destination, const Node *source);
