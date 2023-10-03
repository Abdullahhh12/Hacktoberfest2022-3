#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int bfactor;
}node;

node *createnode(int val);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
void bst(node **root,int val);
int depth(node *root);
void leftrotate(node **root);
void rightrotate(node **root);
void calculatebfactor(node **root);
void balancenode(node **root);
void insertAVL(node **root,int val);

node *createnode(int val){
    node *tmp = (node *)malloc(sizeof(node));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data = val;
    return tmp;
}

void preorder(node *root){
    if (root == NULL)
        return;

    printf("%d ",root->data);

    preorder(root->left);

    preorder(root->right);
}

void inorder(node *root){
    if (root == NULL)
        return;

    inorder(root->left);

    printf("%d ",root->data);

    inorder(root->right);
}

void postorder(node *root){
    if (root == NULL)
        return;

    postorder(root->left);

    postorder(root->right);

    printf("%d ",root->data);
}

void bst(node **root,int val){
    if (*root == NULL){
        createnode(val);
        return;
    }

    if ((*root)->data < val)
        bst(&(*root)->left,val);

    if ((*root)->data > val)
        bst(&(*root)->right,val);
}

int depth(node *root){
    if (root == NULL)
        return 0;

    int left = depth(root->left);
    int right = depth(root->right);

    if (left > right)
        return left + 1;

    else    
        return right + 1;
}

void leftrotate(node **root){
    if (*root == NULL)
        return;

    node *tmp = (*root)->right->left;
    (*root)->right->left = *root;
    *root = (*root)->right;
    (*root)->left->right = tmp;
}

void rightrotate(node **root){
    if (*root == NULL)
        return;

    node *tmp = (*root)->left->right;
    (*root)->left->right = *root;
    *root = (*root)->left;
    (*root)->right->left = tmp;
}

void calculatebfactor(node **root){
    if (*root == NULL)
        return;

    (*root)->bfactor = depth((*root)->left) - depth((*root)->right);
}

void balancenode(node **root){
    if (*root == NULL)
        return;

    calculatebfactor(&(*root));

    if ((*root)->bfactor > 1){
        if ((*root)->left->bfactor < 0)
            leftrotate(&(*root)->left);

        rightrotate(root);
    }

    else if ((*root)->bfactor < -1){
        if ((*root)->right->bfactor > 0)
            rightrotate(&(*root)->right);

        leftrotate(root);
    }

    else    
        return;
}

void insertAVL(node **root,int val){
    if (*root == NULL){
        *root = createnode(val);
        return;
    }

    if (val < (*root)->data)
        insertAVL(&(*root)->left,val);

    if (val > (*root)->data)
        insertAVL(&(*root)->right,val);

    balancenode(root);
}

int main(){
    node *root = NULL;

    insertAVL(&root, 1);
    insertAVL(&root, 3);
    insertAVL(&root, 2);
    insertAVL(&root, 5);
    insertAVL(&root, 4);
    insertAVL(&root, 7);
    insertAVL(&root, 6);

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}
