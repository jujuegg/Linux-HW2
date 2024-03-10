#include <stdlib.h>

typedef struct __node {
    struct __node *left, *right;
    struct __node *next;
    long value;
} node_t;

inline static void list_add(node_t **list, node_t *node_t)
{
    node_t->next = *list;
    *list = node_t;
}

inline static node_t *list_tail(node_t **left)
{
    while ((*left) && (*left)->next)
        left = &((*left)->next);
    return *left;
}

inline static int list_length(node_t **left)
{
    int n = 0;
    while (*left) {
        ++n;
        left = &((*left)->next);
    }
    return n;
}

inline static node_t *list_construct(node_t *list, int n)
{
    node_t *node = malloc(sizeof(node_t));
    node->next = list;
    node->value = n;
    return node;
}

inline static void list_free(node_t **list)
{
    node_t *node = (*list)->next;
    while (*list) {
        free(*list);
        *list = node;
        if (node)
            node = node->next;
    }
}
void quick_sort(node_t **list);
