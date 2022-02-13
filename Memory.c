#include "Memory.h"

void set_memory(Memory *mem){
    mem->root = NULL;
}

void read(struct MEMORY *mem, FILE **assembly){
    char line[30];
    int address = 0x0;
    char *temp;

    while( fgets(line, 30, *assembly) != NULL ){
        if(line[0] != '\n'){
            temp = strtok(line, "\n");
            mem->root = insert(mem->root, address, temp);
            address++;
        }
    }
}