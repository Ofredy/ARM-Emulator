#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdint.h>
#include "Memory.h"
#include "AVLTree.h"

// CPU structure with registers and flags
typedef struct CPU {
    int R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, SP, LR, PC;
    int N, Z, C, V;
    node *registerRoot;
    node *fucntionRoot;
} CPU;

// initalizing function
void reset(CPU *cpu);

void register_dictionary(CPU *cpu);

void function_dictionary(CPU *cpu);

void execute(CPU *cpu, Memory *mem);

// fetching functions
char * fetch_function(Memory *mem, int addy);

char * fetch_operand1(Memory *mem, int addy);

char * fetch_operand2(Memory *mem, int addy, int numOperands);

char * fetch_operand3(Memory *mem, int addy);

// MOV functions
void MOV(int *R_store, int num);
void MOVS(CPU *cpu, int *R_store, int num);

// LDR functions
void LDR(int *R_store, int num);
void LDRS(CPU *cpu, int *R_store, int num);

// Adding functions
void ADD(int *R_store, int num1, int num2);
void ADDS(CPU *cpu, int *R_store, int num1, int num2);

// Subtracting Functions
void SUB(int *R_store, int num1, int num2);
void SUBS(CPU *cpu, int *R_store, int *num1, int *num2);

// Multiplication Functions
void MUL(int *R_store, int num1, int num2);
void MULS(CPU *cpu, int *R_store, int num1, int num2);

// Division Functions
void UDIV(CPU *cpu, int *R_store, int num1, int num2);
void SDIV(CPU *cpu, int *R_store, int num1, int num2);

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

#endif