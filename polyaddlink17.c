#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff;
    int expo;
    struct Node* next;
};

struct Node* createNode(int coeff,int expo){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertNode(struct Node* head,int coef, int expo){
    struct Node* newNode = createNode(coef,expo);
    if (head == NULL){
        return newNode;
    }
    struct Node* temp = head;
    while(temp_next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}