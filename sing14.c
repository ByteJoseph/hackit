#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data){
    struct Node* newNode = createNode(data);
    if (head == NULL){
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void inertAtPosition(int data, int position){
    struct Node* newNode = createNode(data);
    if (position == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for (int i =1; i < position -1 && temp != NULL; i++)
    {
        temp = temp->next;
    }  
    if (temp == NULL){
        printf("Position out of bounds\n");
        free(newNode);
        return;
    } 
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteNode(int data){
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == data){
        head = temp->next;
        free(temp);
        printf("Node with data %d deleted\n", data);
        return;
    }
    while (temp!= NULL && temp->data != data){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Node with data %d not found\n", data);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted\n", data);

}
void displayList(){
    struct Node* temp = head;
    if (temp == NULL){
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// main function with do while loop switch and read data from user
int main(){
    int choice, data, position;
    do {
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Node\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                inertAtPosition(data, position);
                break;
            case 4:
                printf("Enter data of node to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 5:
                displayList();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}