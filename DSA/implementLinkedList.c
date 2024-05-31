// Implement a Linked List using C 

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new Node with given data
Node* createNode(int data) {
    // Allocate memory for a new Node
    Node* newNode = (Node*)malloc(sizeof(Node));
    // Check if memory allocation was successful
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    // Initialize the Node with given data and NULL next pointer
    newNode->data = data;
    newNode->next = NULL;
    // Return the newly created Node
    return newNode;
}

// Function to append a new Node with given data to the end of the list
void append(Node** head, int data) {
    // Create a new Node with given data
    Node* newNode = createNode(data);
    // If the list is empty, make the new Node the head of the list
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    // Traverse the list to find the last Node
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Append the new Node to the end of the list
    temp->next = newNode;
}

// Function to display the elements of the list
void display(Node* head) {
    // Start from the head of the list
    Node* temp = head;
    // Traverse the list and print each Node's data
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    // Print NULL to signify the end of the list
    printf("NULL\n");
}

// Main function
int main() {
    // Initialize the head of the list to NULL
    Node* head = NULL;
    // Append some elements to the list
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    // Display the elements of the list
    display(head);
    // Return 0 to indicate successful execution
    return 0;
}
