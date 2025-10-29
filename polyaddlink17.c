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
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
struct Node* addPoly(struct Node* poly1, struct Node* poly2){
    struct Node* result = NULL;
    while(poly1 != NULL && poly2 != NULL){
        if (poly1->expo > poly2->expo){
            result = insertNode(result,poly1->coeff,poly1->expo);
            poly1 = poly1->next;
        }
        else if(poly2->expo>poly1->expo){
            result = insertNode(result,poly2->coeff,poly2->expo);
            poly2 = poly2->next;
        }
        else{
            int sumcoef = poly1->coeff+poly2->coeff;
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
    return result;
}
void display(struct Node* poly){
    if (poly == NULL){
        printf("Cannot display polynomial. It is empty.\n");
        return;
    }
    struct Node* temp = poly;
    while(temp!=NULL){
        printf("%d^%d",temp->coeff,temp->expo);
        temp = temp->next;
        if (temp!=NULL){
            printf(" + ");
        }
    }
    printf("\n");
}
struct Node* takeInput(){
    int n, coeff, expo;
    struct Node* poly = NULL;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("Enter coefficient and exponent of term %d: ",i+1);
        scanf("%d %d",&coeff,&expo);
        poly = insertNode(poly,coeff,expo);
    }
    return poly;
}
void main()
{
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    printf("Enter first polynomial:\n");
    poly1 = takeInput();
    printf("Enter second polynomial:\n");
    poly2 = takeInput();
    printf("First Polynomial: ");
    display(poly1);
    printf("Second Polynomial: ");
    display(poly2);
    sum = addPoly(poly1,poly2);
    printf("Sum of Polynomials: ");
    display(sum);

}