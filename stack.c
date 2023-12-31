#include <stdio.h>
#include <malloc.h>

struct stack
{
int data;
struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int peek(struct stack *);

int main() 
{
int val, option;

do
{
printf("\n Main Menu");
printf("\n 1. Push");
printf("\n 2. Display");
printf("\n 3. Pop");
printf("\n 4. Peek");
printf("\n 5. Exit");
printf("\n Enter your option: ");
scanf("%d", &option);

switch(option)
{
case 1:
printf("\n Enter the number to be pushed on stack: ");
scanf("%d", &val);
top = push(top, val);
break;

case 2:
top = display(top);
break;

case 3:
top = pop(top);
break;

case 4:
val = peek(top);
if (val != -1)
printf("\n The value at the top of stack is: %d", val);
else
printf("\n STACK IS EMPTY");
break;

}

}while(option != 5);

return 0;
}



struct stack *push(struct stack *top, int val)
{
struct stack *ptr;
ptr = (struct stack*)malloc(sizeof(struct stack));
ptr -> data = val;
if(top == NULL)
{
ptr -> next = NULL;
top = ptr;
}
else
{
ptr -> next = top;
top = ptr;
}
return top;
}



struct stack *display(struct stack *top)
{
struct stack *ptr;
ptr = top;
if(top == NULL)
printf("\n STACK IS EMPTY");
else
{
while(ptr != NULL)
{
printf("\n %d", ptr -> data);
ptr = ptr -> next;
}
}
return top;
}


struct stack *pop(struct stack *top)
{
struct stack *ptr;
ptr = top;
if(top == NULL)
printf("\n STACK UNDERFLOW");
else
{
top = top -> next;
printf("\n The value being deleted is: %d", ptr -> data);
free(ptr);
}
return top;
}
int peek(struct stack *top)
{
if(top==NULL)
return -1;
else
return top ->data;
}