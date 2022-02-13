#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include <string.h>
#include "AVLTree.h"

typedef struct MEMORY{
    node *root;  
} Memory;

void set_memory(Memory *mem);

void read(struct MEMORY *mem, FILE **assembly);

#endif 