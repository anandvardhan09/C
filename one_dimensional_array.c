#include <stdio.h>
#include <stdlib.h>
int main()
{
int n, *list;
printf("\nEnter the no of elements:");
scanf("%d", &n);
if (n < 1)
{
printf("Incorrect Value");

}
list = (int *) malloc(n * sizeof(int));
if (!list)
{
printf("Insufficient Memory");

}
/* Allow the users to enter values and display it*/
/* print the values */
free(list);
return 0;
}