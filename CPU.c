#include "CPU.h"

// initalizing functions
void reset(struct CPU *cpu){
    cpu->R0 = 0x0;
    cpu->R1 = 0x0;
    cpu->R2 = 0x0;
    cpu->R3 = 0x0;
    cpu->R4 = 0x0;
    cpu->R5 = 0x0;
    cpu->R6 = 0x0;
    cpu->R7 = 0x0;
    cpu->R8 = 0x0;
    cpu->R9 = 0x0;
    cpu->R10 = 0x0;
    cpu->R11 = 0x0;
    cpu->R12 = 0x0;
    cpu->SP = 0x20000400;
    cpu->LR = 0xFFFFFFFF;
    cpu->PC = 0x0;
    cpu->N = 0;
    cpu->Z = 0;
    cpu->C = 0;
    cpu->V = 0;
}

void register_dictionary(CPU *cpu){
    node *root;
    root = insert_string(root, 0, "R0");
    root = insert_string(root, 1, "R1");
    root = insert_string(root, 2, "R2");
    root = insert_string(root, 3, "R3");
    root = insert_string(root, 4, "R4");
    root = insert_string(root, 5, "R5");
    root = insert_string(root, 6, "R6");
    root = insert_string(root, 7, "R7");
    root = insert_string(root, 8, "R8");
    root = insert_string(root, 9, "R9");
    root = insert_string(root, 10, "R10");
    root = insert_string(root, 11, "R11");
    root = insert_string(root, 12, "R12");
    root = insert_string(root, 13, "SP");
    root = insert_string(root, 14, "LR");
    root = insert_string(root, 15, "PC");
    cpu->registerRoot = root;
}

void function_dictionary(CPU *cpu){
    node *root;
    root = insert_string(root, 0, "MOV");
    root = insert_string(root, 1, "MOVS");
    root = insert_string(root, 2, "LDR");
    root = insert_string(root, 3, "LDRS");
    root = insert_string(root, 4, "ADD");
    root = insert_string(root, 5, "ADDS");
    root = insert_string(root, 6, "SUB");
    root = insert_string(root, 7, "SUBS");
    root = insert_string(root, 8, "MUL");
    root = insert_string(root, 9, "MULS");
    root = insert_string(root, 10, "UDIV");
    root = insert_string(root, 11, "SDIV");
    root = insert_string(root, 12, "LSL");
    root = insert_string(root, 13, "LSLS");
    root = insert_string(root, 14, "LSR");
    root = insert_string(root, 15, "LSRS");
}

// Execute function
void execute(CPU *cpu, struct MEMORY *mem){
    int counter = 0;
    while(counter < mem->numLines){
        



    }
}

// fetch operations
char * fetch_function(Memory *mem, int addy){
    char *code = search(mem->root, addy);
    char *function = malloc(sizeof(code));
    strcpy(function, code);
    function = strtok(function, " ");
    return function;
}

char * fetch_operand1(Memory *mem, int addy){
    char *code = search(mem->root, addy);
    char *operand1 = malloc(sizeof(code));
    strcpy(operand1, code);
    operand1 = strtok(operand1, " "); 
    operand1 = strtok(NULL, ",");
    if(operand1[0] == '#')
        return "Error";
    else
        return operand1;
}

char * fetch_operand2(Memory *mem, int addy, int numOperands){
    char *code = search(mem->root, addy);
    char *operand2 = malloc(sizeof(code));
    strcpy(operand2, code);
    operand2 = strtok(operand2, " "); 
    operand2 = strtok(NULL, ",");
    if(numOperands == 2){
        operand2 = strtok(NULL, " ");
        if(operand2[0] == '#')
            strcpy(&operand2[0], &operand2[1]);            
        return operand2;
    }
    else if(numOperands == 3){
        operand2 = strtok(NULL, ",");
        strcpy(&operand2[0], &operand2[1]);
        if(operand2[0] == '#')
            strcpy(&operand2[0], &operand2[1]);   
        return operand2;
    }
}

char * fetch_operand3(Memory *mem, int addy){
    char *code = search(mem->root, addy);
    char *operand3 = malloc(sizeof(code));
    strcpy(operand3, code);
    operand3 = strtok(operand3, " "); 
    operand3 = strtok(NULL, ",");
    operand3 = strtok(NULL, ",");
    operand3 = strtok(NULL, " ");
    if(operand3[0] == '#'){
        strcpy(&operand3[0], &operand3[1]);
        return operand3;
    }
    else
        return operand3;
}

// MOV functions
void MOV(int *R_store, int num){
    *R_store = num;
}

void MOVS(CPU *cpu, int *R_store, int num){
    *R_store = num;
    if(sizeof(*R_store) > sizeof(int32_t))
        cpu->C = 1;
    else if(*R_store == 0)
        cpu->Z = 1;
    else if(*R_store < 0)
        cpu->N = 1;
    else if(*R_store > 2147483647 || *R_store < -2147483648)
        cpu->V = 1;
}

// LDR functions
void LDR(int *R_store, int num){
    *R_store = num;
}

void LDRS(CPU *cpu, int *R_store, int num);

// Adding functions
void ADD(int *R_store, int num1, int num2){
    *R_store = num1 + num2;
}

void ADDS(CPU *cpu, int *R_store, int num1, int num2);

// Subtracting Functions
void SUB(int *R_store, int num1, int num2){
    *R_store = num1 - num2;
}

void SUBS(CPU *cpu, int *R_store, int *num1, int *num2);

// Multiplication Functions
void MUL(int *R_store, int num1, int num2){
    *R_store = num1 * num2;
}

void MULS(CPU *cpu, int *R_store, int num1, int num2);

// Division Functions
void UDIV(CPU *cpu, int *R_store, int num1, int num2);
void SDIV(CPU *cpu, int *R_store, int num1, int num2);

// Shift Functions
void LSL(int *R_store, int R_shift, int num);
void LSLS(CPU *cpu, int *R_store, int R_shift, int num);
void LSR(int *R_store, int R_shift, int num);
void LSRS(CPU *cpu, int *R_store, int R_shift, int num);
void ASR(int *R_store, int R_shift, int num);
void ASRS(CPU *cpu, int *R_store, int R_shift, int num);

// Logical Functions
void AND(int *R_store, int Rn, int mask);
void ORR(int *R_store, int Rn, int mask);
void EOR(int *R_store, int Rn, int mask);
void BIC(int *R_store, int Rn, int mask);
void ORN(int *R_store, int Rn, int mask);