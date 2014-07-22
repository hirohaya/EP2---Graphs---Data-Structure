#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int key;
    struct node *next;

} Node;

Node *create_node(int key);
void insert_node(Node *graph, Node *node);

#endif /*NODE_H*/

