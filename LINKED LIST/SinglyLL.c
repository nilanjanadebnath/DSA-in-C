/*Impliment a singly linked list with the following menu driven operation:
1.INSERT AT BEGINNING, 2.INSERT AT ENDING, 3.DELETE FROM BEGINNING, 
4.DELETE FROM ENDING, 5.INSERT AT POSITION, 6.DELETE FROM POSITION, 
7.DELETE BY DATA, 8.DISPLAY, 0.EXIT.
-----------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
//INSERT AT BEGINNING
void insbeg(){
  struct node* n=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter data:");
  scanf("%d", &n->data);
  if(head==NULL){
     head=n;
     head->next=NULL;
    }
  else{
     n->next=head;
     head=n; 
    }
}
//INSERT AT ENDING
void insend(){
  struct node* n=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter data:");
  scanf("%d", &n->data);
  if(head==NULL){
     head=n;
     head->next=NULL;
    }
  else{
     struct node *ptr=head;
     while(ptr->next!=NULL){
         ptr=ptr->next;
        }
     ptr->next=n;
     n->next=NULL;
    }
}
//DELETE FROM BEGINNING
void delbeg(){
    if(head==NULL){
        printf("\nUnderflow!!");
    }
    else{
        struct node *del=head;
        head=head->next;
        printf("\n%d is deleted.",del->data);
        free(del);
    }
}
//DELETE FROM ENDING
void delend(){
    if(head==NULL){
        printf("\nUnderflow!!");
    }
    else if(head->next==NULL){
        struct node *del=head;
        head=NULL;
        printf("\n%d is deleted.",del->data);
        free(del);
    }
    else{
        struct node *ptr=head, *pre_ptr;
        while(ptr->next!=NULL){
         pre_ptr = ptr;
         ptr = ptr->next;
        }
        printf("\n%d  is deleted!!", ptr->data);
        free(ptr);
        pre_ptr->next=NULL;
    }
}
//INSERT AT POSITION
void inspos(){
    int pos;
    printf("\nEnter position:");
    scanf("%d",&pos);
    if(pos==0) insbeg();
    else{
        struct node *n=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter data:");
        scanf("%d",&n->data);
        struct node *ptr=head;
        for(int i=1;i<pos;i++){
            ptr = ptr->next;
        }
        n->next = ptr->next;
        ptr->next = n;
    }
}
//DELETE FROM POSITION
void delpos(){
    int pos;
    printf("\nEnter position:");
    scanf("%d", &pos);
    if(head==NULL){
        printf("\nUnderflow!!");
    }
    else if(pos==0) delbeg();
    else{
     struct node *ptr=head;
     for(int i=1;i<pos;i++){
         ptr = ptr->next;
        }
     struct node *del= ptr->next;
     ptr->next = ptr->next->next;
     printf("\n%d is deleted.", del->data);
     free(del);
    }
}
//DELETE BY DATA
void deldata(){
    int search_data;
    printf("\nEnter search data:");
    scanf("%d", &search_data);
    if(head==NULL){
        printf("\nUnderflow!!");
    }
    else if(head->data==search_data) delbeg();
    else{
        int found=0;
        struct node *ptr=head;
        while(ptr->next!=NULL){
            if(ptr->next->data==search_data){
                found=1;
                break;
            }
            ptr = ptr->next;
        }
        if(found==1){
            struct node *del = ptr->next;
            ptr->next = ptr->next->next;
            printf("\n%d is deleted.", del->data);
            free(del);
        }
        else{
            printf("\n Not found.");
        }
    }
}
//DISPLAY
void disp(){
    if(head==NULL){
        printf("\nEmpty!!");
    }
    else{
        struct node *ptr=head;
        while(ptr!=NULL){
            printf("%d ->", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL");
    }
}
//MENU DRIVEN OPARETION
int main(){
    printf("\n1. INSERT AT BEGINNING\n2. INSERT AT ENDING\n3. DELETED FROM BEGINNING\n4. DELETED FROM ENDING\n5. INSERT AT POSITION\n6. DELETE AT POSITION\n7. DELETE BY DATA\n8. DISPLAY\n0. EXIT");
    int choice;
    while(1){
        printf("\nEnter choice:");
        scanf("%d", &choice);
        if(choice==1) insbeg();
        else if(choice==2) insend();
        else if(choice==3) delbeg();
        else if(choice==4) delend();
        else if(choice==5) inspos();
        else if(choice==6) delpos();
        else if(choice==7) deldata();
        else if(choice==8) disp();
        else if(choice==0) break;
        else printf("\nInvalid Choice!!");
    }
}