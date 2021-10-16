#ifndef H_HASH_TABLE
#define H_HASH_TABLE
#define HASH_MAX_SIZE 1000000

typedef struct Item {
    char key[63];
    int value;
    struct Item* prev;
} Item;

typedef struct ItemNode {
    Item* item;
    struct ItemNode* next;
} ItemNode;

typedef struct {
    int cap;
    ItemNode** items;
    Item* last;
} HashTable;

HashTable* hash_create(int cap);
void hash_destroy(HashTable* hashTable);
void hash_insert(HashTable* hashTable, Item* item);
void hash_update(HashTable* hashTable, Item* item);
void hash_delete(HashTable* hashTable, Item* item);
Item* hash_get(HashTable* hashTable, const char* key);

Item* item_create(char* key, int value);
void item_destroy(Item* item);

ItemNode* items_create(Item* item);
void items_destroy(ItemNode* items);
void items_prepend(ItemNode** items, ItemNode* node);
Item* items_get(ItemNode* items, const char* key);
void items_delete(ItemNode* items, const char* key);
#endif
