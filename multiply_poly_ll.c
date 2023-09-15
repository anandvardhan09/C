
#include <stdio.h>
#include <stdlib.h>


struct node {
    int coeff;
    int exp;
    struct node* next;
};


struct node* create_22054408(int coeff, int exp) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;
    return newnode;
}


void addnode(struct node** poly, int coeff, int exp) {
    struct node* newnode = create_22054408(coeff, exp);
    if (*poly == NULL) {
        *poly = newnode;
    } else {
        struct node* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}


struct node* multiply_poly_22054408(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;


    while (poly1 != NULL) {
        struct node* ptr1 = poly2;
        while (ptr1 != NULL) {
            int new_coeff = poly1->coeff * ptr1->coeff;
            int new_exp = poly1->exp + ptr1->exp;
            addnode(&result, new_coeff, new_exp);
            ptr1 = ptr1->next;
        }
        poly1 = poly1->next;
    }

    return result;
}


void display_22054408(struct node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (poly != NULL) {
        printf("%d", poly->coeff);
        if (poly->exp != 0) {
            printf("x^%d", poly->exp);
        }

        if (poly->next != NULL) {
            printf(" + ");
        } else {
            printf("\n");
        }

        poly = poly->next;
    }
}


void freePolynomial(struct node* poly) {
    while (poly != NULL) {
        struct node* ptr1 = poly;
        poly = poly->next;
        free(ptr1);
    }
}

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;

   
    addnode(&poly1, 1, 2);
    addnode(&poly1, 3, 1);
    addnode(&poly1, 6, 0);

   
    addnode(&poly2, 3, 3);
    addnode(&poly2, 5, 2);
    addnode(&poly2, 7, 0);

  
    printf("First Polynomial: ");
    display_22054408(poly1);


    printf("Second Polynomial: ");
    display_22054408(poly2);

  
    struct node* result = multiply_poly_22054408(poly1, poly2);
    printf("Multiplication of Polynomials: ");
    display_22054408(result);


    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
