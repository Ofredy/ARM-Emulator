#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdint.h>

// CPU structure with registers and flags
struct CPU {
    int R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, SP, LR, PC;
    int N, Z, C, V;
};

// initalizing function
void reset(struct CPU *cpu);

// MOV functions
void MOV(int *R_store, int num);
void MOVS(struct CPU *cpu, int *R_store, int num);

// LDR functions
void LDR(int *R_store, int num);
void LDRS(struct CPU *cpu, int *R_store, int num);

// Adding functions
void ADD(int *R_store, int num1, int num2);
void ADDS(struct CPU *cpu, int *R_store, int num1, int num2);

// Subtracting Functions
void SUB(int *R_store, int num1, int num2);
void SUBS(struct CPU *cpu, int *R_store, int *num1, int *num2);

// Multiplication Functions
void MUL(int *R_store, int num1, int num2);
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

#endif