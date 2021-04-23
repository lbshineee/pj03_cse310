/* File: graph.h
 *
 * Header file for the Graph ADT.
 */

#ifndef _graph_h
#define _graph_h 1

#include <stdio.h>

typedef struct TAG_VERTEX{
	int color;	/* color of vertex: in {0, 1, 2} */
	int pi;		/* predecessor of vertex: in {1, 2, ..., n} */
	float dist;	/* current distance from source vertex */
	int pos;	/* position in the heap array */
	char *name;	/* name of the POI represented by this vertex */
}VERTEX;
typedef VERTEX *pVERTEX;
/*
 * V[1], V[2], ..., V[n] form an array of n structs of type VERTEX
 * V[i] represents vertex i.
 * V[i].color is the color of vertex i.
 * V[i].pi is either 0 or the predecessor of vertex i.
 * V[i].key is the current value of the source to i distanvce.
 * V[i].name is not used at this momnet.
 */

//node for adjancent list
typedef struct TAG_NODE{
	int u;		/* start vertex u... Reduandant safe guard */
	int v;		/* end vertex v */
	float w;	/* weight of edge (u, v) */
	TAG_NODE *next;		/* pointer to next node */
}NODE;
typedef NODE *pNODE;
/*
A[1], A[2], ..., A[n] form an array of n pointers of type pNODE.
A[i] is the adjacency list of vertex i.
*/

typedef struct TAG_PATH{
	int vertex;
	TAG_PATH *next;
}PATH;

typedef PATH *pPATH;

void printPath(int n, int source, int destination, int s, int t);
int dijkstra(int n, pNODE *A, int s, int t, int flag);

#endif
