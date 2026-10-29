#include <stdio.h>
#include <stdlib.h>

struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
};

// Create a new node
struct treenode* createNode(int data)
{
    struct treenode *newNode;

    newNode = (struct treenode*)malloc(sizeof(struct treenode));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node into BST
struct treenode* insert(struct treenode *tree, int data)
{
    if (tree == NULL)
        return createNode(data);

    if (data < tree->data)
        tree->left = insert(tree->left, data);
    else if (data > tree->data)
        tree->right = insert(tree->right, data);

    return tree;
}

// Inorder Traversal
void inorder(struct treenode *tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%d ", tree->data);
        inorder(tree->right);
    }
}

// Search
struct treenode* search(struct treenode *tree, int key)
{
    if (tree == NULL || tree->data == key)
        return tree;

    if (key < tree->data)
        return search(tree->left, key);

    return search(tree->right, key);
}

int main()
{
    struct treenode *tree = NULL;
    struct treenode *result;
    int n, data, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        tree = insert(tree, data);
    }

    printf("\nInorder Traversal: ");
    inorder(tree);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    result = search(tree, key);

    if (result != NULL)
        printf("%d found in BST.\n", key);
    else
        printf("%d not found in BST.\n", key);

    return 0;
}
