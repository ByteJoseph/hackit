#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
int Stack[50];
int size,top;
void initStack()
{
	top = -1;
}

bool isEmpty()
{
	return top == -1;
}
bool isFull()
{
	return top==size-1;
}

void push(int item)
{
	if (isFull())
	  printf("Stack overflow\n");
	else{
		top++;
		Stack[top] = item;
		printf("Element %d added to Stack \n",item);
	}
}

int pop()
{
	if (isEmpty())
	{
		printf("Stack underflow \n");
		return INT_MIN;
	}
	else{
		int num = Stack[top];
		top--;
		return num;
	}
}
void display()
{
	if (isEmpty())
	    printf("Stack is Empty \n");
	else{
		for (int i=top;i>=0;i--)
		{
			printf("%d\n",Stack[i]);
		}
	}
}
int main()
{
	int choice,item,popped;
	printf("Enter the size of the Stack: ");
	scanf("%d",&size);
	initStack();
	printf("Stack created with size %d\n",size);
	do{
		printf(" 1.push \n 2.pop \n 3.Display \n 4.Exit \n Enter your choice ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			   printf("Enter the element to be added : ");
			   scanf("%d",&item);
			   push(item);
			   break;
		    case 2:
		        popped = pop();
		        if (popped != INT_MIN)
		        printf("The element popped is %d \n",popped);
		        break;
		    case 3:
		        display();
		        break;
		    case 4:
		        printf("Exiting...\n");
		        break;
		    default:
		        printf("Invalid choice \n");
		}
	}while(choice != 4);
return 0;
}
			   
