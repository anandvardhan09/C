
#include <stdio.h>
#include <stdlib.h>


struct node {
    int coeff;
    int exp;
    struct node* next;
};


struct node* create_22054408(int coeff, int exp) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;
    return new_node;
}

void add_22054408(struct node** poly, int coeff, int exp) {
    struct node* new_node = create_22054408(coeff, exp);
    if (*poly == NULL) {
        *poly = new_node;
    } else {
        struct node* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}


struct node* add_poly_22054408(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;
    
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            add_22054408(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            add_22054408(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int sum_coeff = poly1->coeff + poly2->coeff;
            if (sum_coeff != 0) {
                add_22054408(&result, sum_coeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    

    while (poly1 != NULL) {
        add_22054408(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    
    while (poly2 != NULL) {
        add_22054408(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    
    return result;
}


void displayPolynomial(struct node* poly) {
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


void free_poly_22054408(struct node* poly) {
    while (poly != NULL) {
        struct node* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    
    add_22054408(&poly1, 4, 2);
    add_22054408(&poly1, 3, 1);
    add_22054408(&poly1, 5, 0);
    

    add_22054408(&poly2, 1, 3);
    add_22054408(&poly2, 1, 2);
    add_22054408(&poly2, 7, 0);
    
    printf("First Polynomial: ");
    displayPolynomial(poly1);
    
  
    printf("Second Polynomial: ");
    displayPolynomial(poly2);
    
   
    struct node* result = add_poly_22054408(poly1, poly2);
    printf("Sum of Polynomials: ");
    displayPolynomial(result);
    
   
    free_poly_22054408(poly1);
    free_poly_22054408(poly2);
    free_poly_22054408(result);
    
    return 0;
}
