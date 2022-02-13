#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int address;
    char *instruction;
    struct Node *left;
    struct Node *right;
    int height;
} node;

int max(int a, int b);

int height(node *N);

node * new_node(int addy, char *line);

node * right_rotate(node *y);

node * left_rotate(node *x);

int get_balance_factor(node *N);

node * insert(node *N, int addy, char *line);

char * search(node *root, int addy);

void print_tree(node *root);

void delete_tree(node *root);

#endif