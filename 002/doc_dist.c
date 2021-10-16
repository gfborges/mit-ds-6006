#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "hash_table.h"
#include "parse_file.h"
#include "doc_dist.h"

double dot_product(HashTable* doc1, HashTable* doc2) {
    double x = 0, value = 0;
    Item *curr, *item;
    curr = doc1->last;
    while(curr) {
        item = hash_get(doc2, curr->key);
        value = item ? item->value : 0;
        x += curr->value * value;
        curr = curr->prev;
    }
    return x;
}

double normal(HashTable* doc) {
    int x = 0;
    Item* curr = doc->last;
    printf("[x]");
    while(curr){
        x += curr->value * curr->value;
        printf("(%s,%d)", curr->key, curr->value);
        curr = curr->prev;
    }
    printf("\n");
    return sqrt(x);
}

double doc_dist(HashTable* doc1, HashTable* doc2) {
    double prod, doc1_norm, doc2_norm;
    prod = dot_product(doc1, doc2);
    doc1_norm = normal(doc1);
    doc2_norm = normal(doc2);
    return acos(prod / (doc1_norm*doc2_norm));
}

