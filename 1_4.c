#include <stdio.h>

struct Complex {
  float real;
  float Imaginary;
};

void addComplexNum(struct Complex c1, struct Complex c2, struct Complex *result);
void multiplyComplexNum(struct Complex c1, struct Complex c2, struct Complex *result);

int main() {
  int choice;
  struct Complex c1, c2, result;

printf("\nEnter 1st complex number: ");
    scanf("%f", &c1.real);
    scanf("%f", &c1.Imaginary);

printf("\nEnter 2nd complex number: ");
    scanf("%f", &c2.real);
    scanf("%f", &c2.Imaginary);



printf("\n\nComplex Number Operations Menu\n");
printf("1. Add Complex Numbers\n");
printf("2. Multiply Complex Numbers\n");
printf("\nEnter your choice: ");
scanf("%d", &choice);

switch (choice) {
    case 1:
    addComplexNum(c1, c2, &result); 
    printf("\n Sum : %f + %f i\n", result.real, result.Imaginary);
    break;

    case 2:
    multiplyComplexNum(c1, c2, &result);
    printf("\nThe product of the complex numbers is: %f + %f i\n", result.real, result.Imaginary);
    break;

    default:
    printf("\nInvalid choice!\n");
}
  

  return 0;
}

void addComplexNum(struct Complex c1, struct Complex c2, struct Complex *result) {
  result->real = c1.real + c2.real;
  result->Imaginary = c1.Imaginary + c2.Imaginary;
}

void multiplyComplexNum(struct Complex c1, struct Complex c2, struct Complex *result) {
  result->real = c1.real * c2.real - c1.Imaginary * c2.Imaginary;
  result->Imaginary = c1.real * c2.Imaginary + c1.Imaginary * c2.real;
}
