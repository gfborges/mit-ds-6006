#include <stdio.h>
#include "hash_table.h"

void print_item(Item* item) {
    printf("[%s] => %d\n", item->key, item->value);
}

int main() {
    const char strs[][4] = {"the", "cat", "dog"};
    HashTable* table = hash_create(10);
    Item* the = item_create(strs[0], 2);
    Item* cat = item_create(strs[1], 1);
    Item* dog = item_create(strs[2], 1);
    hash_insert(table, the);
    the->value++;
    print_item(the);
    Item* item = hash_get(table, strs[0]);
    print_item(item);
    hash_destroy(table);
}

