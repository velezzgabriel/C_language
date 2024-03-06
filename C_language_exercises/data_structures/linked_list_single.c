#include <stdio.h>
#include <stdlib.h>


// Define the structure for a linked list node:
struct Node {
    int data;
    struct Node *next;
};


//Create a new node:
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL ) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL ;
    return newNode;
}


//Insert a node at the beginning:
void insertAtBeginning(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}


//Insert a node at the end:
void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}


//Delete a node by value:
void deleteNode(struct Node **head, int value) {
    struct Node *current = *head;
    struct Node *prev = NULL;
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Value not found in the list.\n");
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}


//Traverse and print the list:
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


//Reverse single linked list
void reverseList(struct Node **head) {
    struct Node *current = *head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next; // Save the next node
        current->next = prev; // Reverse the link

        prev = current; // Move to the next pair of nodes
        current = next;
    }

    *head = prev; // Update the head to point to the new first node (previously the last node)
}

// reverse second half of a linked list
void reverseSecondHalf(struct Node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        // The list is empty or has only one element; nothing to reverse.
        return;
    }

    // Find the midpoint of the list
    struct Node* slow = *head;
    struct Node* fast = *head;
    struct Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    struct Node* current = slow;
    struct Node* next = NULL;
    struct Node* newHead = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = newHead;
        newHead = current;
        current = next;
    }

    // Adjust the links to connect the first and reversed second halves
    if (prev != NULL) {
        prev->next = newHead;
    } else {
        *head = newHead;
    }
}

//In the main function, you can create a list, perform operations, and print the list. Here's an example:
int main() {
    struct Node *myList = NULL;

    insertAtEnd(&myList, 10);
    insertAtEnd(&myList, 10);
    insertAtEnd(&myList, 10);
    insertAtEnd(&myList, 10);
    insertAtBeginning(&myList, 5);
    insertAtBeginning(&myList, 5);
    insertAtBeginning(&myList, 5);
    insertAtBeginning(&myList, 5);
    insertAtEnd(&myList, 20);
    insertAtEnd(&myList, 20);
    insertAtEnd(&myList, 20);
    insertAtEnd(&myList, 20);
    deleteNode(&myList, 5);
    printList(myList);

    return 0;
}