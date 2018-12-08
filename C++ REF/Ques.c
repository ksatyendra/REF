#include<stdio.h>
#include<stdlib.h>

struct bnode
{
    int key;
    struct bnode *left, *right;
};

struct bnode *newnode(int key)
{
    struct bnode *temp =  (struct bnode *)malloc(sizeof(struct bnode));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct bnode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct bnode* insert(struct bnode* root, int key)
{
    if (root == NULL)
        return newnode(key);
    if (key < root->key)
        root->left  = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

int main()
{
    struct bnode *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);

    return 0;
}
