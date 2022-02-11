#include "cpu.h"

// initalizing function
void reset(struct CPU *cpu){
    cpu->R0 = 0;
    cpu->R1 = 0;
    cpu->R2 = 0;
    cpu->R3 = 0;
    cpu->R4 = 0;
    cpu->R5 = 0;
    cpu->R6 = 0;
    cpu->R7 = 0;
    cpu->R8 = 0;
    cpu->R9 = 0;
    cpu->R10 = 0;
    cpu->R11 = 0;
    cpu->R12 = 0;
    cpu->SP = 0;
    cpu->LR = 0;
    cpu->PC = 0;
    cpu->N = 0;
    cpu->Z = 0;
    cpu->C = 0;
    cpu->V = 0;
}

// MOV functions
void MOV(int *R_store, int num){
    *R_store = num;
}

void MOVS(struct CPU *cpu, int *R_store, int num){
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

void LDRS(struct CPU *cpu, int *R_store, int num);

// Adding functions
void ADD(int *R_store, int num1, int num2){
    *R_store = num1 + num2;
}

void ADDS(struct CPU *cpu, int *R_store, int num1, int num2);

// Subtracting Functions
void SUB(int *R_store, int num1, int num2){
    *R_store = num1 - num2;
}

void SUBS(struct CPU *cpu, int *R_store, int *num1, int *num2);

// Multiplication Functions
void MUL(int *R_store, int num1, int num2){
    *R_store = num1 * num2;
}

void MULS(struct CPU *cpu, int *R_store, int num1, int num2);

// Division Functions
void UDIV(struct CPU *cpu, int *R_store, int num1, int num2);
void SDIV(struct CPU *cpu, int *R_store, int num1, int num2);

// Shift Functions
void LSL(int *R_store, int R_shift, int num);
void LSR(int *R_store, int R_shift, int num);
void ASR(int *R_store, int R_shift, int num);

// Logical Functions
void AND(int *R_store, int Rn, int mask);
void ORR(int *R_store, int Rn, int mask);
void EOR(int *R_store, int Rn, int mask);
void BIC(int *R_store, int Rn, int mask);
void ORN(int *R_store, int Rn, int mask);