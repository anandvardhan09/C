#include <stdio.h>

void compare (int *a, int *b)
{
    if (*a < *b)
    {
        printf("%d is smaller than %d\n", *a, *b);
    }
    else if (*a > *b)
    {
        printf("%d is greater than %d\n", *a, *b);
    }
    else
    {
        printf("Both are equal\n");
    }
}

int main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    compare(&a, &b);

    return 0;
}