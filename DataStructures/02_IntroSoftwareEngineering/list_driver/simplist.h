#define MAXLIST 300

typedef char ListEntry;

typedef struct list
{
    int count;
    ListEntry entry[MAXLIST];
} List;

void list_create(List *);
void list_clear(List *);
bool list_empty(const List *);
bool list_full(const List *);
int list_size(const List *);
void list_add(ListEntry, List *);
void list_traverse(List *, void(*)(ListEntry));
void list_copy(List *, const List *);
void copy_list(List *destination, const List *source);

