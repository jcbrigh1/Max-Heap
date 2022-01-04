//
//  main.cpp
//  main
//
//  Created by Jason Bright on 3/3/20.
//  Copyright © 2020 Jason Bright. All rights reserved.
//

//============================================================================
//#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "heap.h"
#include <fstream>
#include <iostream>
using namespace std;
int main() {
	// variables for the parser...

    char c; 				//initial character passed in
    int i, v, f, n, k;		//integers passed in after the char
    ifstream myFile;		//used to read HEAPinput.txt
    Element myElement;		//used to store Elements such as delete max
    bool initialized = 0;	//used to know if the heap was already initialized

    Heap myHeap; 	//the heap to be used throughout the program
    while(1){
		cout << "(S):\t\t exit the program\n";
		cout << "(C n):\t\t create new heap of size n\n";
		cout << "(R):\t\t reads from \"HEAPinput.txt\" and builds heap from file\n";
		cout << "(W):\t\t print heap size, capacity, and contents\n";
		cout << "(I k f):\t insert element with key k and flag f\n";
		cout << "(D  f):\t\t delete max element\n";
		cout << "(K f i v):\t increases key of element K with index i to v with flag f\n";
		cout << "[F]:\t\t (1) completes operation as normal. (2) prints heap before operation\n";
        c = nextCommand(&i, &v, &f, &n, &k); //calling nextCommand for kb input
        switch (c) {
	    /* S
	     * terminates the program with exit code 0
	     */
            case 's':
            case 'S': printf("COMMAND: %c\n", c);  exit(0);

	    /* C n
	     *Will create a new heap if not already done so
	     *otherwise will use the old heap to "resize"
	     */
            case 'c': 
            case 'C': printf("COMMAND: %c %d\n", c, n);
                if(initialized && n >= 0){
					myHeap.capacity = n;
					myHeap.size = 0;
				}
                else if(n >= 0){
                    myHeap = Initialize(n);
                    initialized = 1; //keeping track of whether already initializede
                }
                else{
                    printf("Error: invalid heap capacity\n");
                }
                break;

	    /* R
	     * reads file "HEAPinput.txt" and places
	     * elements into the heap and builds a max
	     * heap using linear build function
	     */
            case 'r':
            case 'R': printf("COMMAND: %c\n", c);
                if(!(initialized)){  
                    printf("Error: heap not initialized\n");
                }
                else{ 		//setting up file I/O
		                    ifstream myfile;
					myfile.open("HEAPinput.txt");
					int input;
					myfile >> input;
					int size = input;
					struct Element myElementArray[size+1];
					if(!myfile){  //making sure the file actually opened
					   cout << "Unable to open" << endl;
					}
	                if(myHeap.capacity < input){ //making sure there is room in the heap
	                    printf("Error: array size exceeds heap capacity\n");
	                }
					else{
						int i = 1;
						while(myfile >> input){
							//printf("1. Input %d\n", input);
							myElementArray[i].key = input;
							i++;
						}
						BuildHeap(&myHeap, myElementArray, size);
					}
					myfile.close();
                } 
                break;

	    /* W
	     * prints the heap size, capacity, and contents
	     */
            case 'w':
            case 'W': printf("COMMAND: %c\n", c);
                if(!(initialized)){ //making sure the heap is initialized
                    printf("Error: heap not initialized\n");
                }
                else{
                    printHeap(&myHeap); //simply calling the print function
                }
                break;

	    /* I
	     * inserts element with key k, and flag f
	     */
            case 'i':
            case 'I': printf("COMMAND: %c %d %d\n", c, f, k);
                if(!(initialized)){	//making sure it has been initialized
                    printf("Error: heap not initialized\n");
                }
                else{
                    Insert(&myHeap, f, k); //simply calling insert function
                }
                break;

	    /* D f
	     * deletes max key with flag set to f
	     */
            case 'd':
            case 'D': printf("COMMAND: %c %d\n", c, f);
                if(!(initialized)){
					printf("Error: heap not initialized\n");
				}
                else if(myHeap.size != 0){
					if(f == 1 || f == 2){
                		myElement = DeleteMax(&myHeap, f); //deleting the max
                		printf("Deleted max = %d\n", myElement.key);//printing the max
					}
					else{
						printf("Error: invalid flag value\n");
					}
				}
				else{
					printf("Error: heap empty\n");

				}
                break;

	    /* K f i v
	     * increases key of eleement with index i to v with flag f
 	     */
            case 'k':
            case 'K': printf("COMMAND: %c %d %d %d\n", c, f, i, v);
                if(!(initialized)){ //making sure it was initialized
					printf("Error: heap not initialized\n");
				}
                else if(!(f == 1 || f == 2)){ //making sure flag vlue is valid
					printf("Error: invalid flag value\n");
				}
				else if(i < 1 || i > myHeap.size){ //making sure index is in range
					printf("Error: invalid index\n");
				}
				else{
                	IncreaseKey(&myHeap, f, &(myHeap.H[i]), v);//increasing the key
				}
                break;


            default: break;
        }
    }
}
//END OF MAIN
