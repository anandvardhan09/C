#include <stdio.h>

#include <stdlib.h>


struct node {
    int row;
    int col;
    int value;
    struct node* next;
};
    
struct node* sparse1 = NULL;
struct node* sparse2 = NULL;
struct node* sparse3 = NULL;

struct node * create_sparse_ll_22054408(struct node *start)
{

  struct node *new_node,*ptr;
  int r,c,v;
  printf("\n Enter -1 in row or col to end");
  printf("\n Enter sparse matrix :");
  printf("\n R C Value\n");
  scanf("%d",&r);
  scanf("%d",&c);
  scanf("%d",&v);


  while(r != -1 && c != -1 )
  {

   new_node=(struct node *)malloc(sizeof(struct node));
   new_node->row=r;
   new_node->col=c;
   new_node->value=v;
   new_node->next=NULL; 


   if(start==NULL)
   {
     start=new_node;
     ptr = start;
   }
   else
   {

     ptr->next=new_node;
     ptr=new_node; 
    }
        printf("\n");
        scanf("%d",&r);
        scanf("%d",&c);
        scanf("%d",&v);
    }
 return start;
}


struct node *display_sparse_22054408(struct node *start)
{
  struct node *ptr;
  ptr=start;

    printf("\n R \t C \t Value \t");
  while(ptr != NULL)
  {
    printf("\n %d \t %d \t %d \t",ptr->row,ptr->col,ptr->value);
    ptr=ptr->next;
  }
  return start;
}



struct node *insert_end_22054408(struct node *start,int r, int c,int v)
{

  struct node *ptr, *new_node;

  if(start==NULL)
  {

   new_node=(struct node *)malloc(sizeof(struct node));
   new_node->row=r;
   new_node->col=c;
   new_node->value=v;
   new_node->next=NULL;
   start=new_node;
  }
  else
  {
    ptr=start;
    while(ptr->next != NULL)
      {ptr=ptr->next;}

    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->row=r;
    new_node->col=c;
    new_node->value=v;
    new_node->next=NULL;
    ptr->next=new_node;
  }

 return start;
}




struct node *add_sparse_22054408(struct node *sparse1,struct node *sparse2,struct node *sparse3)
{
 
 struct node *ptr1,*ptr2;


ptr1=sparse1;
ptr2=sparse2;

while(ptr1 != NULL && ptr2 != NULL)
{
 
  if(ptr1->row == ptr2->row)
  {
    if(ptr1->col == ptr2->col){
        sparse3=insert_end_22054408(sparse3,ptr1->row,ptr1->col,(ptr1->value+ptr2->value));
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    else{
        if(ptr1->col < ptr2->col)
           {sparse3=insert_end_22054408(sparse3,ptr1->row,ptr1->col,ptr1->value);}
        else
            {sparse3=insert_end_22054408(sparse3,ptr2->row,ptr2->col,ptr2->value);}
    }
  }
  else{
      if(ptr1->row < ptr2->row)
         {sparse3=insert_end_22054408(sparse3,ptr1->row,ptr1->col, ptr1->value);}
      else
          {sparse3=insert_end_22054408(sparse3,ptr2->row,ptr2->col, ptr2->value);}
  }
}
if(ptr2 == NULL){
      
      while(ptr1 != NULL){
      sparse3=insert_end_22054408(sparse3,ptr1->row,ptr1->col, ptr1->value);
      ptr1 = ptr1->next;}
}
if(ptr1 == NULL){
      while(ptr2 != NULL){
      sparse3=insert_end_22054408(sparse3,ptr2->row,ptr2->col, ptr2->value);
      ptr2 = ptr2->next;}
}

return sparse3;
}





int main() {

    printf("enter sparse matrix 1: ");
    sparse1=create_sparse_ll_22054408(sparse1);
    
    
  
    printf("enter sparse matrix 2: ");
    sparse2=create_sparse_ll_22054408(sparse2);


    printf("Sum of matrices in sparse matrix form");
    sparse1=display_sparse_22054408(sparse1);
    sparse3=display_sparse_22054408(sparse2);
   
    // sparse3=add_sparse_22054408(sparse1,sparse2,sparse3);
    // sparse3=display_sparse_22054408(sparse3);
    
    return 0;
}
