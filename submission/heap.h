/*
Name: Liuboxuan Jiang
Date: 03/01/2021
Course: CSE 310
Instructor: Guoliang Xue
Description: For Project 1. 
This cpp file declares the data types and functions for the heap structure.
*/
#ifndef _heap_h
#define _heap_h 1

#include <stdio.h>
#include "graph.h"

typedef struct TAG_ELEMENT{
	float key;	/* key value */
	int vertex;	/* corresponding vertex */
}ELEMENT;

typedef ELEMENT *pELEMENT;

typedef struct TAG_HEAP{
	int capacity;		/* max size of the heap */
	int size;		/* current size of the heap */
	pELEMENT *H;	/* pointer to pointers to elements */
}HEAP;

void heapFree(HEAP *heap);
void MovingUp(HEAP *heap, int pos);

HEAP *heapInit(int capacity);
void BuildHeap(HEAP *heap, int *flag, int *heapify_count);
void heapPrint(HEAP *heap);
void WriteHeap(HEAP *heap);
int Insert(HEAP *heap, pELEMENT element);
pELEMENT DeleteMin(HEAP *heap, int *flag, int *count_Heapify);
int DecreaseKey(HEAP *heap, int pos, int newKey);
void min_Heapify(HEAP *heap, int index, int *flag, int *heapify_count);


int parent(int i);
int left(int i);
int right(int i);
void swap(HEAP *heap, int a, int b);
#endif


