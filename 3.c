#include <stdio.h>

int main(){
int i,j;
int a[3][2] = {{1,2},{3,4},{1,5}};
int (*p)[2]=a;
for (i=0; i<3; i++)
    {
    for (j=0;j<2;j++)
        {
            printf("%d", a[i][j]);
            printf("%d\n", *(*(p+i)+j));
            }
    }
    return 0;
}