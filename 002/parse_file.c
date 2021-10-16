#include <stdlib.h>
#include <stdio.h>
#include "hash_table.h"

#define BUFFER_SIZE 256 

int is_alphanumeric(char c) {
    switch(c){
        case 'a' ... 'z':
            return 1;
        case 'A' ... 'Z':
            return 1;
        case '0' ... '9':
            return 1;
        default: 
            return 0;
    }
}

void count_word(HashTable* hash_tbl, char* key) {
    Item* item = NULL;
    item = hash_get(hash_tbl, key);
    if(item) {
        item->value++;
    } else {
        item = item_create(key, 1);
        hash_insert(hash_tbl, item);
    }
}

void read_line(HashTable* hash_tbl, char* buffer)  {
    int start = 0;
    char c;
    for (int i=0; buffer[i]; ++i) {
        c = buffer[i];
        if (!is_alphanumeric(c)) {
            buffer[i] = '\0';
            count_word(hash_tbl, &buffer[start]);
            start = i + 1;
        }
    }
}

void read_lines(HashTable* hash_tbl, FILE* file)  {
    char buffer[BUFFER_SIZE];
    while(fgets(buffer, BUFFER_SIZE, file)) {
        read_line(hash_tbl, buffer);
    }
}

void read_file(HashTable* hash_tbl, char* filename) {
    FILE *file = fopen(filename, "r");
    read_lines(hash_tbl, file);
    fclose(file);
}

