#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void push(int data){
  struct Node* newNode = createNode(data);
  newNode->next = top;
  top = newNode;
  printf("Pushed %d to stack\n",data);
}

void pop(){
    if (top==NULL){
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    printf("Popped %d\n",temp->data);
    free(temp);
}
void Display(){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    while (temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// implement main function and do while loop and switch , read data from user
int main(){
    int choice, data;
    do {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 4);
    return 0;
}