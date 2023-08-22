#include <stdio.h>
struct Books
    {
        char title[50];
        char author[50];
        char subject[50];
        int id;
    }book;
    
void main()
{
    int i;
    struct Books book[10];

    printf("enter details of 10 books");
    for(i=0;i<10;i++)
    {
        printf("\nBook no.: %d",(i+1));
        printf("\n book title:");
        scanf("%s",book[i].title);
        printf("\n book author:");
        scanf("%s",book[i].author);
        printf("\n book subject:");
        scanf("%s",book[i].subject);
        printf("\n book id:");
        scanf("%d",&book[i].id);
    }

    printf("\nBook details entered:");

    for(i=0;i<10;i++)
    {
        printf("\n\nBook no.: %d",(i+1));
        printf("\ntitle : %s",book[i].title);
        printf("\nauthor : %s",book[i].author);
        printf("\nsubject : %s",book[i].subject);
        printf("\nid : %d",book[i].id);

    }

    

}