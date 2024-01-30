#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new binary tree node.
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to build the binary tree.
struct TreeNode* buildTree() {
    int val;
    printf("Enter the value of the node (or -1 for NULL): ");
    scanf("%d", &val);

    if (val == -1) {
        return NULL;
    }

    struct TreeNode* root = newNode(val);
    printf("Enter left child of %d:\n", val);
    root->left = buildTree();
    printf("Enter right child of %d:\n", val);
    root->right = buildTree();

    return root;
}

// Function to find the Closest Common Ancestor (CCA) of two nodes in a binary tree.
struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }

    struct TreeNode* left = findNode(root->left, val);
    struct TreeNode* right = findNode(root->right, val);

    return (left != NULL) ? left : right;
}
struct TreeNode* findCCAHelper(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    struct TreeNode* left = findCCAHelper(root->left, p, q);
    struct TreeNode* right = findCCAHelper(root->right, p, q);

    if (left && right) {
        return root;
    }

    return (left != NULL) ? left : right;
}
struct TreeNode* findCCA(struct TreeNode* root, int val1, int val2) {
    struct TreeNode* p = findNode(root, val1);
    struct TreeNode* q = findNode(root, val2);

    if (p == NULL || q == NULL) {
        return NULL;
    }

    if (p == q) {
        return p;
    }

    return findCCAHelper(root, p, q);
}



int main() {
    // Building the binary tree
    printf("Build the binary tree:\n");
    struct TreeNode* root = buildTree();

    // Taking user input for finding the Closest Common Ancestor (CCA)
    int val1, val2;
    char choice;

    do {
        printf("\nEnter value of first node: ");
        scanf("%d", &val1);
        printf("Enter value of second node: ");
        scanf("%d", &val2);

        // Find the Closest Common Ancestor (CCA)
        struct TreeNode* cca = findCCA(root, val1, val2);
        if (cca != NULL) {
            printf("CCA of %d and %d: %d\n", val1, val2, cca->val);
        } else {
            printf("Nodes not found or CCA doesn't exist.\n");
        }

        printf("\nDo you want to find CCA for another pair of nodes? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
