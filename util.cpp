//
//  util.cpp
//  main
//
//  Created by Jason Bright on 3/3/20.
//  Copyright © 2020 Jason Bright. All rights reserved.
//

#include "util.h"
#include "heap.h"
#include <fstream>
using namespace std;


//=============================================================================
char nextCommand(int *i, int *v, int *f, int *n, int *k)
{
    char c;
    while(1){
        scanf("%c", &c); //taking input of first character
        if (c ==  ' ' || c == '\t' || c == '\n'){ //blank spaces
            continue;
        }
        if (c == 'S' || c == 's'){ //stopping the program
            break;
        }
        if(c == 'C' || c == 'c'){ //takes in int n
            scanf("%d", n);
            break;
        }
        if(c == 'R' || c == 'r'){ //merely breaks the loop
            break;
        }
        if(c == 'W' || c == 'w'){ //merely breaks the loop
            break;
        }
        if(c == 'I' || c == 'i'){ //takes in input for flag and key
            scanf("%d", f); scanf("%d", k);
            break;
        }
        if(c == 'D' || c == 'd'){ //takes in flag value
            scanf("%d",f);
            break;
        }
        if (c == 'K' || c == 'k'){ //takes in flag, key, and index value
            scanf("%d", f); scanf("%d", i); scanf("%d", v);
            break;
        }
        printf("Invalid Command\n"); //if none else, it was an invalid command
    }
    return c;
}
//=============================================================================
