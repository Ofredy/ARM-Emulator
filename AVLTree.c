#include "AVLTree.h"

int max(int a, int b){
    return (a>b)? a:b;
}

int height(node *N){
    if(N == NULL)
        return 0;
    return N->height;
}

node * new_node(int addy, char line[]){
    node *temp = (node*)malloc(sizeof(node));
    temp->address = addy;
    temp->instruction = line;
    temp->height = 1;
    temp->left = NULL;
    temp->right = NULL;
    return (temp);
}

node * right_rotate(node *y){
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node * left_rotate(node *x){
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int get_balance_factor(node *N){
    if(N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node * insert(node *N, int addy, char line[]){
    if(N == NULL)
        return (new_node(addy, line));

    if(addy < N->address)
        N->left = insert(N->left, addy, line);
    else if(addy > N->address)
        N->right = insert(N->right, addy, line);
    else
        return N;

    N->height = 1 + max(height(N->left), height(N->right));

    int balance = get_balance_factor(N);

    // left left 
    if( balance > 1 && addy < N->left->address)
        return right_rotate(N);
    // right right
    if( balance < -1 && addy > N->right->address)
        return left_rotate(N);
    // left right
    if( balance > 1 && addy > N->left->address){
        N->left = left_rotate(N->left);
        return right_rotate(N);
    }
    // right left
    if( balance < -1 && addy < N->right->address){
        N->right = right_rotate(N->right);
        return left_rotate(N);
    }
    
    return N;
}

char * search(node *root, int addy){
    if(root == NULL)
        return "Address not found";

    if(addy < root->address)
        search(root->left, addy);
    else if(addy > root->address)
        search(root->right, addy);
    else if(addy == root->address)
        return root->instruction;
}

void print_tree(node *root){
    if(root != NULL){
        printf("Address: %d, Instruction: %s\n", root->address, root->instruction);
        print_tree(root->left);
        print_tree(root->right);
    }
}

void delete_tree(node *root){
    if(root){
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}