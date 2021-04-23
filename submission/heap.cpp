/*
Name: Liuboxuan Jiang
Date: 03/01/2021
Course: CSE 310
Instructor: Guoliang Xue
Description: For Project 1. 
This .cpp file creates basic functionality for the heap structure.
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "heap.h"
using namespace std;

extern VERTEX *V;
//heapInit function for initialize the heap with passing capacity n
HEAP *heapInit(int capacity){
	HEAP *aHeap;
	aHeap = (HEAP *) calloc(1, sizeof(HEAP));
	if(!aHeap){
	printf("Error: cannot allocate memory for heap\n");
	}else{
	aHeap->capacity = capacity;
	aHeap->size = 0;
	aHeap->H = (pELEMENT *) calloc(capacity+1, sizeof(pELEMENT));
		if(!aHeap->H){
		printf("Error: cannot allocate memory for heap array\n");
		}
	}
	return aHeap;
}

//build min heap function
void BuildHeap(HEAP *heap, int *flag, int *heapify_count){
	for(int i=heap->size/2; i>=1; i--){
		min_Heapify(heap, i, flag, heapify_count);
	}	
}

//heapPrint function for printing the information of the passing heap.
void heapPrint(HEAP *aHeap){
	//print the heap informaiton 
	cout << "capacity=" << aHeap->capacity << ", size=" << aHeap->size << endl;
	//print the heap elements
	for(int i=1; i <= aHeap->size; i++){
		cout << aHeap->H[i]->key;
		if(i != aHeap->size)
			cout << ", ";
		else
			cout << endl;
	}
		
}
//insert function.
int Insert(HEAP *heap, pELEMENT item){
	if(heap->size >= heap->capacity){
		printf("Error in HeapInsert: Heap full...\n");
		return 1;
	}
	heap->size++;
	heap->H[heap->size] = item;
	V[heap->H[heap->size]->vertex].pos = heap->size;
	MovingUp(heap, heap->size);
	return 0;
}

//decreasekey
int DecreaseKey(HEAP *heap, int pos, int newKey){
	if(pos<1 || pos>heap->size || newKey>=heap->H[pos]->key){
	//	printf("Error: invalid call to DecreaseKey\n");
		return 1;
	}
	heap->H[pos]->key = newKey;
	MovingUp(heap, pos);
	return 0;
}

void MovingUp(HEAP *heap, int pos){
	int parent; 
	pELEMENT temp;

	//printf("BEG MovingUp\n");
	parent = pos/2;
	if(pos > 1 && heap->H[pos]->key < heap->H[parent]->key){
		temp = heap->H[pos];
		heap->H[pos] = heap->H[parent];
		heap->H[parent] = temp;
		V[heap->H[pos]->vertex].pos = pos;
		V[heap->H[parent]->vertex].pos = parent;
		MovingUp(heap, parent);
	}
	//printf("END MovingUp\n");
}
//min-heapify function or moving down function.
void min_Heapify(HEAP *heap, int index, int *flag, int *count_Heapify){
	int smallest;
	int l = left(index);
	int r = right(index);

	if(*flag == 1){
		*count_Heapify = *count_Heapify + 1;
	}
	//if left child is greater than right child and l is inside of the size of heap, set largest = l;
	if((l <= heap->size) && (heap->H[l]->key < heap->H[index]->key))
		smallest = l;
	else
		smallest = index;
	if((r <= heap->size) && (heap->H[r]->key < heap->H[smallest]->key))
		smallest = r;
	if(smallest != index){
		swap(heap, index, smallest);
		min_Heapify(heap, smallest, flag, count_Heapify);
	}
}

//extrac min function
pELEMENT DeleteMin(HEAP *heap, int *flag, int *count_Heapify){
	pELEMENT min, last;

	if(heap->size <= 0){
		printf("Error in DeleteMin: heap empty\n");
		return NULL;
	}
	min = heap->H[1];
	last = heap->H[heap->size--];
	heap->H[1] = last;
	V[heap->H[1]->vertex].pos = 1;
	min_Heapify(heap, 1, flag, count_Heapify);
	V[min->vertex].pos = 0;
	return min;
}

//free heap
void heapFree(HEAP *heap)
{
	free(heap->H);
	free(heap);
}

//other trival funcitons
//find parent function
int parent(int i){return i/2;}
int left(int i){return 2*i;}
int right(int i){return 2*i+1;}
void swap(HEAP *heap, int a, int b){
	int temp = heap->H[a]->key;
	heap->H[a]->key = heap->H[b]->key;
	heap->H[b]->key = temp;
}

