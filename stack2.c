#include <stdio.h>

#define MAX 10
int stack[MAX], topA = -1, topB = MAX;

void pushA(int val) {
    if (topA == topB - 1) {
        printf("\n Stack A Overflow");
    } else {
        topA += 1;
        stack[topA] = val;
    }
}

int popA() {
    int val;
    if (topA == -1) {
        printf("\n Stack A Underflow");
        val = -999;
    } else {
        val = stack[topA];
        topA--;
    }
    return val;
}

void display_stackA() {
    int i;
    if (topA == -1) {
        printf("\n Stack A is Empty");
    } else {
        printf("\n Stack A Contents: ");
        for (i = topA; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void pushB(int val) {
    if (topB - 1 == topA) {
        printf("\n Stack B Overflow");
    } else {
        topB -= 1;
        stack[topB] = val;
    }
}

int popB() {
    int val;
    if (topB == MAX) {
        printf("\n Stack B Underflow");
        val = -999;
    } else {
        val = stack[topB];
        topB++;
    }
    return val;
}

void display_stackB() {
    int i;
    if (topB == MAX) {
        printf("\n Stack B is Empty");
    } else {
        printf("\n Stack B Contents: ");
        for (i = topB; i < MAX; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int option, val;

    do {
        printf("\n Menu");
        printf("\n 1. Push Stack A");
        printf("\n 2. Push Stack B");
        printf("\n 3. Pop in Stack A");
        printf("\n 4. Pop in Stack B");
        printf("\n 5. Display A");
        printf("\n 6. Display B");
        printf("\n 7. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n Enter the value to push on Stack A: ");
                scanf("%d", &val);
                pushA(val);
                break;

            case 2:
                printf("\n Enter the value to push on Stack B: ");
                scanf("%d", &val);
                pushB(val);
                break;

            case 3:
                val = popA();
                if (val != -999)
                    printf("\n The value popped from Stack A = %d", val);
                break;

            case 4:
                val = popB();
                if (val != -999)
                    printf("\n The value popped from Stack B = %d", val);
                break;

            case 5:
                printf("\n The contents of Stack A are: ");
                display_stackA();
                break;

            case 6:
                printf("\n The contents of Stack B are: ");
                display_stackB();
                break;
        }
    } while (option != 7);

    return 0;
}