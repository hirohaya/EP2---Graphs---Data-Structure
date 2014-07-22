#ifndef GRAPH_H
#define GRAPH_H


#include "node.h"
#include "file.h"

#define maxV 1000
#define boolean int
#define TRUE 1
#define FALSE 0

void graph_init(int size);
Node *create_node(int key);
void create_graph(char *filename);
void print_graph();
int DIGRAPHpath(int s, int t);
void pathR(int v);
boolean is_adjacent(int v, int w);
void print_path(int s, int t);

#endif /*GRAPH_H*/

