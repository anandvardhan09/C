#include <stdlib.h>
#include <stdio.h>
int main(){
int i,n;
int *a;
int *p = a;
printf("enter the no. of aaray:");
scanf("%d",&n);

a = (int *)malloc(n * sizeof(int));

if(a == NULL){
    printf("memory allocation failed.\n");
}

printf("enter %d elements of array",n);

for (i=0; i<n; i++)
{
    scanf("%d",&a[i]);
}

printf("entered data is ");
for(i=0;i<n;i++){
    printf("%d",a[i]);
}
free(a);
return 0;

}