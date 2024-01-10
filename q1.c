#include <stdio.h>
#include <stdlib.h>

struct btree
{
    int data;
    struct btree* left;
    struct btree* right;
};

struct btree* create(struct btree* root, int n)
{
    if (root == NULL)
    {
        struct btree* newnode = (struct btree*)malloc(sizeof(struct btree));
        if (newnode == NULL)
        {
            printf("MEMORY ALLOCATION ERROR!\n");
            return NULL;
        }

        newnode->data = n;
        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
    }

    if (n > root->data)
    {
        root->right = create(root->right, n);
    }
    else if (n < root->data)
    {
        root->left = create(root->left, n);
    }
    else
    {
        printf("Key already exists in the binary search tree\n");
    }

    return root;
}

struct btree* search(struct btree* root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return search(root->left, key);
    }

    return search(root->right, key);
}

void printInorder(struct btree* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    printf("%d ", node->data);

    printInorder(node->right);
}

void printPreorder(struct btree* node)
{
    if (node == NULL)
        return;
 
    printf("%d ", node->data);
 
    printPreorder(node->left);
 
    printPreorder(node->right);
}

void printPostorder(struct btree* node)
{
    if (node == NULL)
        return;
 
    printPostorder(node->left);
 
    printPostorder(node->right);
 
    printf("%d ", node->data);
}


int main()
{
    int n, key;
    struct btree* root = NULL;

    do
    {
        printf("Enter number (0 to exit): ");
        scanf("%d", &n);
        if (n != 0)
        {
            root = create(root, n);
        }
    } while (n != 0);

    printf("Enter key to search: ");
    scanf("%d", &key);

    struct btree* result = search(root, key);
    if (result != NULL)
    {
        printf("Key found\n");
    }
    else
    {
        root = create(root, key);
        printf("Key inserted in the binary search tree\n");
    }

    printf("INORDER: ");
    printInorder(root);
    printf("\n");

    printf("PREORDER: ");
    printPreorder(root);
    printf("\n");

    printf("POSTORDER: ");
    printPostorder(root);
    printf("\n");

    return 0;
}