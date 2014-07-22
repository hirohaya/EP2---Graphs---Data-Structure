#include "node.h"

/*Creates a new node with key "key"*/
Node *create_node(int key){

  Node *new_node;

    new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = NULL;

    return new_node;
}

/*Makes a sorted insertion of a new node created by create_node in the graph[i] indicating an edge
  comming from the node "i" to the new node*/
void insert_node(Node *graph, Node *node){

  Node *p;
  int aux;

    p = graph;

    while(node->key > p->key && p->next != NULL)	p = p->next;
   
    node->next = p->next;
    p->next = node;
    
    if(p->key > node->key){	
        aux = node->key;
        node->key = p->key;
        p->key = aux;
    }
}

