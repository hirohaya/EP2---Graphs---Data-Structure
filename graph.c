#include "graph.h"

static int lbl[maxV];
static int parent[maxV];
static int size;
static Node *graph;


/*Initialize the graph array and set each node next member as NULL*/
void graph_init(int size){

  int i;

    graph = malloc((size)*sizeof(Node));

    for (i = 0; i < size; i++){
        graph[i].next = NULL;
        graph[i].key = -1;
    }
}



/*This function does everything, since initializing the graph with the graph_init
  function and calling*/
void create_graph(char *filename){

  FILE *pFile; 
  int index;
  int key;

    pFile = fopen(filename, "r");
    size = get_size(pFile);
    graph_init(size);


    while(!feof(pFile)){
        if(fscanf(pFile, "%d", &index) == 1 && fscanf(pFile, "%d", &key) == 1){
	    insert_node(&graph[index], create_node(key));
	}
    }

    fclose(pFile);
    print_graph();
}


/*Print everything about the graph, the number of vertieces and edges, out
  put and input decree from each node with output_decree and input_decree 
  function and the vertices list with every node outputs. 
  Everything is printed in the terminal line. Also, this funtion verifies
  the existence of a path between two nodes until a negative number is 
  set to terminate the process.*/
void print_graph(){

  int i;
  int s;
  int edges;
  int *input_decree;
  int *output_decree;
  Node *p;

    input_decree = malloc((size)*sizeof(int));
    output_decree = malloc((size)*sizeof(int));
    edges = 0;

    for(i = 0; i < size; i++){
	input_decree[i] = 0;
	output_decree[i] = 0;
    }

    for(i = 0; i < size; i++){
        fprintf(stdout, "%d -> ", i);
        for(p=graph[i].next; p!= NULL; p=p->next){
            fprintf(stdout, "%d   ", p->key);
	    input_decree[p->key]++;
	    output_decree[i]++;
	    edges++;
	}
    	fprintf(stdout, "\n");
    }

    fprintf(stdout, "\nGraph has %d vertices.\nGraph has %d edges.\n\n", (size), edges);
    
    for(i = 0; i < size; i++)
	    fprintf(stdout, "Vertice %d:\n\tOutput decree %d\n\tInput decree %d\n\n", i, 
		    output_decree[i], input_decree[i]); 
   
    printf("Type two NATURAL NUMBERS representing nodes of the graph to check if exist a path "
	       "between them. Set a negative number into one of inputs to end the operation.\n");
  
    if(scanf("%d %d", &s, &i) == 1);
    while(s >= 0 && i >= 0){
	    if (s > size || i > size)
            printf("Invalid input.\n");
        else {
            if(DIGRAPHpath(s, i) == 1)    print_path(s , i);
            else    printf("No path between node %d and %d.\n", s, i); 
        }
        if(scanf("%d %d", &s, &i) == 1);
    }
    printf("So long, and thanks for all the fish.\n");
}


/*Verifies if there is a path between node "s" and node "t" and return
  1 if exists and 0 if does not exist.
  This function comes from:
  www.ime.usp.br/~pf/algoritmo_para_grafos/aulas/paths2.html */
int  DIGRAPHpath(int s, int t){
    
  int v;

    for(v = 0; v < size; v++)
        lbl[v] = 0;
    pathR(s);
    if(lbl[t] == 0)    return 0;
    else    return 1;

}


/*Verifies if node "v" is adjancet to node "w" due checking if there is a
 node with key "w" in list graph[v]. If they are adjacent, return TRUE if 
 they aren't, return FALSE.*/
boolean is_adjacent(int v, int w){

  Node *p;
	
    p = graph[v].next;
    while(p != NULL && p->key != w)    p = p->next;
    if(p == NULL || p->key != w)    return FALSE;
    else    return TRUE;

}



/*Visits every node that can be visited from node v withou passing by 
  nodes wich lbl is 0.
  This function comes from:
  www.ime.usp.br/~pf/algoritmo_para_grafos/aulas/paths2.html */
void pathR(int v){

    int w;

    lbl[v] = 1;

    for(w = 0; w < size; w++ )
        if(is_adjacent(v, w) && lbl[w] == 0){
	        parent[w] = v;
	        pathR(w);
	}
}


/*Prints the path between node "s" and "t" and the distance between them.
  This function comes from:
  www.ime.usp.br/~pf/algoritmo_para_grafos/aulas/paths2.html */
void print_path(int s, int t){

  int w;
  int *stack;
  int top;
  int dist;

    top = 0;
    dist = 0;

    stack = malloc(size*sizeof(int));

    for(w = t; w != s; w = parent[w])    stack[top++] = w;
    
    printf("%d", s);

    while(top > 0){
	dist++;
        printf("--%d", stack[--top]);
    }
    printf("\n");
    printf("Distance: %d\n", dist);

    free(stack);
}

