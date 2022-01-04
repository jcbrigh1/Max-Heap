//
//  heap.hpp
//  main
//
//  Created by Jason Bright on 3/3/20.
//  Copyright © 2020 Jason Bright. All rights reserved.
//

//#ifndef Heap_hpp
//#define Heap_hpp
#include <stdio.h>

//Element with int Key
struct Element{
    int key;
};

//Heap with capacity, size, and array of Elements
struct Heap{
    int capacity;
    int size;
    struct Element* H;
};

    //declaring all methods
    Heap& Initialize(int n);
    void BuildHeap(Heap* h, Element oldElementArr[], int n);
    void Insert(Heap* h, int flag, int k);
    Element DeleteMax(Heap* h, int flag);
    void IncreaseKey(Heap* h, int flag, Element* index, int value);
    void printHeap(Heap* h);
    void MaxHeapify(Heap* h, int i); //added aditionally for use of other functions

//END heap.h
