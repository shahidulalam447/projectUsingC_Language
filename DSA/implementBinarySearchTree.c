
// Implement a Binary Search Tree using C 
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a Binary Search Tree
typedef struct Node {
    int data;               // Data stored in the node
    struct Node* left;      // Pointer to the left child node
    struct Node* right;     // Pointer to the right child node
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    // Check if memory allocation was successful
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    // Initialize the node with given data and NULL left and right pointers
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with given data into the Binary Search Tree
Node* insert(Node* root, int data) {
    // If the tree is empty, create a new node and make it the root
    if (root == NULL) {
        root = createNode(data);
    } 
    // If the data is less than the current node's data, insert into the left subtree
    else if (data < root->data) {
        root->left = insert(root->left, data);
    } 
    // If the data is greater than or equal to the current node's data, insert into the right subtree
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform inorder traversal of the Binary Search Tree
void inorder(Node* root) {
    if (root == NULL) return;       // Base case: If the root is NULL, return
    inorder(root->left);            // Traverse the left subtree
    printf("%d ", root->data);      // Print the data of the current node
    inorder(root->right);           // Traverse the right subtree
}

// Main function
int main() {
    Node* root = NULL;      // Initialize the root of the Binary Search Tree
    // Insert elements into the Binary Search Tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    // Perform inorder traversal and print the elements of the Binary Search Tree
    inorder(root);
    return 0;               // Return 0 to indicate successful execution
}

