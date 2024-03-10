#include "quick_sort.h"

void quick_sort(struct list_head **head)
{
    struct list_head *begins = malloc(sizeof(struct list_head));
    
    struct list_head *result = malloc(sizeof(struct list_head));
    struct list_head *left = malloc(sizeof(struct list_head));
    struct list_head *right = malloc(sizeof(struct list_head));
    struct list_head *mid = malloc(sizeof(struct list_head));
    
    INIT_LIST_HEAD(begins);
    INIT_LIST_HEAD(result);
    INIT_LIST_HEAD(left);
    INIT_LIST_HEAD(right);
    INIT_LIST_HEAD(mid);
    
    begin_t *all = new_begin(*head);
    list_add_tail(&all->list, begins);
    
    struct list_head *now = begins->next;

    while (now != begins) {
        struct list_head *now_entry_head = list_entry(now, begin_t, list)->head;
        struct list_head *L = now_entry_head->next;
        struct list_head *R = now_entry_head->prev;
        
        if (L != R) {
            node_t *pivot = list_first_entry(now_entry_head, node_t, list);
            list_del(&pivot->list);
            list_add(&pivot->list, mid);
            
            node_t *entry, *safe;
            list_for_each_entry_safe (entry, safe, now_entry_head, list) {
                list_del(&entry->list);
                if (entry->value > pivot->value) {
                    list_add(&entry->list, right);
                } else {
                    list_add(&entry->list, left);
                }
            }
            
            list_splice_tail_init(left, now_entry_head);
            INIT_LIST_HEAD(left);
            
            begin_t *mid_begin = new_begin(mid);
            list_add_tail(&mid_begin->list, begins);
            INIT_LIST_HEAD(mid);

            begin_t *right_begin = new_begin(right);
            list_add_tail(&right_begin->list, begins);
            INIT_LIST_HEAD(right);
            
            now = now->next->next;
            
        } else {
            if (list_is_singular(now_entry_head)) {
                list_splice_init(now_entry_head, result);
            }
            
            struct list_head *del = now_entry_head;
            begin_t *tmp = list_entry(now, begin_t, list);
            
            now = now->prev;

            list_del(&tmp->list);
            list_free(del);
            free(tmp);
        }
    }
    
    *head = result;
}
