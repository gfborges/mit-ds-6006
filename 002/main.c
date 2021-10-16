#include <stdlib.h>
#include <stdio.h>
#include "hash_table.h"
#include "parse_file.h"
#include "doc_dist.h"


int main(int argc, char** argv) {
    if(argc != 3) {
        puts("Usage: doc-dist file1 file2");
        return 1;
    }
    HashTable* doc1 = hash_create(1000);
    HashTable* doc2 = hash_create(1000);
    read_file(doc1, argv[1]);
    read_file(doc2, argv[2]);
    double distance = doc_dist(doc1, doc2);
    printf("%lf\n",distance);
    hash_destroy(doc1);
    hash_destroy(doc2);
}

