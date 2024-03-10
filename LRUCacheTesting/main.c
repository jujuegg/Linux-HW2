#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "lru.h"

bool checkLRU(LRUCache *obj, int key, int value)
{
    struct list_head *head = &obj->dhead;
    struct list_head *first = head->next;
    if (first == head) {
        return false;
    }
    LRUNode *recent = list_entry(first, LRUNode, link);
    return (recent->key == key) && (recent->value == value);
}

int main(void)
{
    int capacity = 5;
    LRUCache *cache = lRUCacheCreate(capacity);

    lRUCachePut(cache, 1, 10);
    lRUCachePut(cache, 2, 20);
    lRUCachePut(cache, 3, 30);
    printf("Get key=1: %d\n", lRUCacheGet(cache, 1));
    lRUCachePut(cache, 4, 40);
    printf("Get key=2: %d\n", lRUCacheGet(cache, 2));
    printf(
        "Test if the key of the first element in dhead is 2, if TRUE, "
        "continue.\n");
    assert(checkLRU(cache, 2, 20));

    lRUCachePut(cache, 5, 50);
    lRUCachePut(cache, 6, 60);
    lRUCachePut(cache, 7, 70);
    printf("Get key=3: %d\n", lRUCacheGet(cache, 3));
    printf(
        "Test if the key of the first element in dhead is 3, if TRUE, "
        "continue.\n");
    assert(checkLRU(cache, 7, 70));

    lRUCacheFree(cache);

    printf("All tests passed!\n");

    return 0;
}
