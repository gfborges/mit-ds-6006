#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include <stdio.h>

HashTable* hash_create(int cap) {
    HashTable* hash_tbl = malloc(sizeof(HashTable));
    hash_tbl->cap = cap;
    hash_tbl->items = malloc(cap * sizeof(ItemNode*));
    for(int i = 0; i < cap; ++i) {
        hash_tbl->items[i] = NULL;
    }
    return hash_tbl;
}

void hash_destroy(HashTable* hash_tbl){
    int i, cap = hash_tbl->cap;
        for (i = 0; i < cap; ++i) {
            if(hash_tbl->items[i] != NULL) {
                items_destroy(hash_tbl->items[i]);
            }
    }
}

int hashf(const char* key, const int mod) {
    int x = 0, i = 0;
    for(i = 0; key[i]; i++) {
        x = x * 37 + key[i];
    }
    return x % mod;
}

void hash_insert(HashTable* hash_tbl, Item* item) {
    int key;
    ItemNode* node = items_create(item);
    key = hashf(item->key, hash_tbl->cap);
    if(hash_tbl->items[key]) {
        hash_tbl->items[key] = node;
    } else {
        items_prepend(&hash_tbl->items[key], node);
    }
    item->prev = hash_tbl->last;
    hash_tbl->last = item;
}

void hash_update(HashTable* hashTable, Item* item);

void hash_delete(HashTable* hashTable, Item* item);

Item* hash_get(HashTable* hash_tbl, const char* key) {
    int index = hashf(key, hash_tbl->cap);
    if(hash_tbl->items[index]) {
        return items_get(hash_tbl->items[index], key);
    }
    return NULL;
}

Item* item_create(char* key, int value){
    Item* item = malloc(sizeof(Item));
    strcpy(item->key,key);
    item->value = value;
    item->prev = NULL;
    return item;
}

void item_destroy(Item* item) {
    free(item);
}

ItemNode* items_create(Item* item){
    ItemNode* node = malloc(sizeof(ItemNode));
    node->item = item;
    node->next = NULL;
    return node;
}

void items_destroy(ItemNode* items){
    ItemNode* curr = items, *next;
    while(curr != NULL){
        next = curr->next;
        item_destroy(curr->item);
        free(curr);
        curr = next;
    }
}

void items_prepend(ItemNode** items, ItemNode* node) {
    node->next = *items;
    *items = node;
}

Item* items_get(ItemNode* items, const char* key ) {
    ItemNode* curr = items,*next;
    while(curr != NULL) {
        next = curr->next;
        if(!strcmp(key, curr->item->key)) {
            return curr->item;
        }
        curr = next;
    }
    return NULL;
}

void items_delete(ItemNode* items, const char* key);

