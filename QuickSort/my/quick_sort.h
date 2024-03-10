#include "list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct __node {
    struct list_head list;
    long value;
} node_t;

typedef struct begins {
    struct list_head list;
    struct list_head *head;
} begin_t;

static inline begin_t *new_begin(struct list_head *head)
{
    begin_t *node = malloc(sizeof(begin_t));
    if (!node)
        return NULL;
    
    struct list_head *head_node = malloc(sizeof(struct list_head));
    INIT_LIST_HEAD(head_node);
    node->head = head_node;
    list_splice_tail(head, node->head);
    
    INIT_LIST_HEAD(&node->list);

    return node;
}

static inline int list_length(struct list_head *head)
{
    if (!head)
        return 0;

    int len = 0;
    struct list_head *li;

    list_for_each (li, head)
        len++;

    return len;
}

static inline void show_list(struct list_head *head)
{
    node_t *cur;
    list_for_each_entry (cur, head, list)
        printf("%ld ", cur->value);
    printf("\n");
}

static inline node_t *new_node(int n)
{
    node_t *node = malloc(sizeof(node_t));
    if (!node)
        return NULL;
        
    INIT_LIST_HEAD(&node->list);
    node->value = n;

    return node;
}

static inline void list_free(struct list_head *l)
{
    if (!l)
        return;

    node_t *entry, *safe;

    list_for_each_entry_safe (entry, safe, l, list) {
        free(entry);
    }
    free(l);
}

void quick_sort(struct list_head **head);

