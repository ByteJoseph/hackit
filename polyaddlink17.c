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
struct Node* addPoly(struct Node* poly1, struct Node* poly2){
    struct Node* result = NULL;
    while(poly1 != NULL && poly2 != NULL){
        if (poly1 ->expo > poly2->expo){
            result = insertNode(result,poly->coeff,poly1->expo);
            poly1 = poly1->next;
        }
        else if(poly2->expo>poly1->expo){
            result = insertNode(result,poly2->coeff,poly2->expo);
            poly2 = poly2->next;
        }
        else{
            int sumcoef = poly1->coefff+poly2->coeff;
            if (sumcoef!=0){
                result = insertNode(result,sumcoef,poly1->expo);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while(poly1!=NULL){
        result = insertNode(result,poly1->coeff,poly1->expo);
        poly1 = poly1->next;
    }
    while(poly2!=NULL){
        result = insertNode(result,poly2->coeff,poly2->expo);
        poly2 = poly2->next;
    }
}