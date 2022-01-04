//
//  heap.cpp
//  main
//
//  Created by Jason Bright on 3/3/20.
//  Copyright © 2020 Jason Bright. All rights reserved.
//

#include "heap.h"
#include <math.h>
#include <cmath>

/* Initialize method, using dynamic
 * memory allocation to create array
 * of elements, setting size to 0
 * and capacity to n, returing the
 * address of the heap created
 */
Heap& Initialize(int n){

    Heap* heap = NULL;
    heap = new Heap;
    heap->H = new Element[n+1];
    heap->capacity = n;
    heap->size = 0;
    return *heap;
}

/* takes an array of elements,
 * stores them into the heap h,
 * then max heapifys at the end
 * to maintain the heap property
 */
void BuildHeap(Heap* h, Element oldElementArr[], int n){
    h->size = n;
    for(int i=1; i<=n; i++)
    {
        h->H[i] = oldElementArr[i];
    }
    for(int i=(n/2); i>=1; i--)
    {
        MaxHeapify(h, i);
    }
}

/* Inserts element with key k, into heap
 * h, and uses flag f, to determine what 
 * to print
 */
void Insert(Heap* h, int flag, int k){
    if(flag == 2)
    {
        printf("Before insert operation:\n");
        printHeap(h);
    }
    else if(flag == 1){}
    else{
        printf("Error: invalid flag value\n");
    }
    if(flag == 1 || flag == 2){
        h->size++; //increasing the size
	
	//if the new size is greater
	//than the old size, memory reallocation
	//must occur
        if(h->size > h->capacity){  
            int oldCapacity = h->capacity;
            Element* temp = h->H;
            if(h->capacity == 0) //if the capacity was 0, set it to 1
            {
                h->H = new Element[1];
                h->capacity++;
            }
            else{ 		
				//if the capacity is already a power of 2, double it
				if(ceil((log2(h->capacity))) == floor(log2(h->capacity))){
                	h->H = new Element[h->capacity*2];
                	h->capacity = (h->capacity)*2;
				}
				else{  //if the capacity is not a power of 2, find the next highest power
					int num = pow(2, ceil(log2(h->capacity)));
					h->H = new Element[num];
					h->capacity = num;
				}
            }
	    //copying the elements
            for(int i=1; i<=oldCapacity; i++){
                h->H[i].key = temp[i].key;
            }
	    //deleting the temporary array
            if(temp != NULL){
               // delete temp;
            }
        }
        int i=h->size;
        h->H[i].key= k-1; //setting a "dummy" value
	//using increase key to do the actuall insert
        IncreaseKey(h, 1, &h->H[i], k); 
        if(flag == 2)
        {
            printf("After insert operation:\n");
            printHeap(h);
        }
    }
}

/* Delete max function will
 * remove the largest element
 * and return it. uses flag value
 * to determine what to print
 */
Element DeleteMax(Heap* h, int flag){
    Element max;
    if(flag == 2)
    {
        printf("Before delete max operation:\n");
        printHeap(h);
    }
    	if(h->size<1)
    	{
    	    printf("Error: Heap empty");
    	}
    	else
    	{
    	    max=h->H[1];
    	    h->H[1]=h->H[h->size];
    	    h->size--;
    	    MaxHeapify(h, 1);
    	}
   	if(flag == 2)
   	{
    printf("After delete max operation:\n");
        printHeap(h);
    }
    return max;
}

/* Increase key function will increase the
 * key of the element pointed to by index, to 
 * the value given, in heap h. uses flag for
 * printing purposes
 */
void IncreaseKey(Heap* h, int flag, Element* index, int value){
    if(flag == 2)
    {
        printf("Before increase key operation:\n");
        printHeap(h);
    }
    if(value < index->key){
        printf("Error: new key is smaller than current key\n");
    }
    else{
        index->key = value; //simply setting the value
        int i=1;	//used to find where in the array the element is
        bool found = 0;
        for(; found == 0 && i<=h->size; i++){ //finding the position
            if(h->H[i].key == index->key){
                break;
            }
        }
	//satisfying the heap propert
        while(i>1 && h->H[(i/2)].key < h->H[i].key){
            Element temp = h->H[i];
            h->H[i]=h->H[i/2];
            h->H[i/2] = temp;
            i=i/2;
        }
    }

    MaxHeapify(h, 1);
    if(flag == 2)
    {
        printf("After increase key operation:\n");
        printHeap(h);
    }
}

/* print heap function prints
 * the capacity, size and element keys
 */
void printHeap(Heap* h){
    printf("Capacity = %d\n", h->capacity);
    printf("Size = %d\n", h->size);
    for(int i=1; i<=h->size; i++)
    {
        printf("%d\n", h->H[i].key);
    }
}

/* max heapify function used to satify heap property
*/
void MaxHeapify(Heap* h, int i){
    int l = 2*i;
    int r = 2*i+1;
    int largest;
    if(l<=h->size && h->H[l].key > h->H[i].key)
        largest = l;
    else
        largest = i;
    if(r<=h->size && h->H[r].key > h->H[largest].key){
        largest = r;
    }
    if(largest != i)
    {
        Element temp = h->H[largest];
        h->H[largest] = h->H[i];
        h->H[i]=temp;
        MaxHeapify(h, largest);
    }
}
