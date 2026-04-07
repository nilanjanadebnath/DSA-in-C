Write a program to impliment 'Singly Circuler Linked List' with the folloeing menu driven options: 
1. Insert at beginning 2. Insert at ending 3. Delete from beginning 4. Delete from ending
5. Display 6. Count node 7. Insert by position 8. Delete by position 9. Delete by data 0. Exit.

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
//INSERT AT BEGINNING
struct node* insbeg(struct node *last){
   struct node *n=(struct node*)malloc(sizeof(struct node));
   printf("enter data: ");
   scanf("%d",&n->data);
    
   if(last==NULL){
     n->next=n;
     last=n;
   }
   else{
     n->next=last->next;
     last->next=n;
   }
   return last;
}
//INSERT AT ENDING
struct node* insend(struct node *last){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&n->data);

    if(last==NULL){
        n->next=n;
        last=n;
    }
    else{
        n->next=last->next;
        last->next=n;
        last=n;
    }
    return last;
}
//DELETE FROM BEGINNING
struct node* delbeg(struct node *last){
    if(last==NULL){
        printf("\nUnderflow");
    }
    else if(last->next==last){
        printf("\n%d is deleted",last->data);
        free(last);
        last=NULL;
    }
    else{
        struct node *del=last->next;
        last->next=del->next;
        printf("\n%d is deleted",del->data);
        free(del);
    }
    return last;
}
//DELETE FROM ENDING
struct node* delend(struct node *last){
    if(last==NULL){
        printf("\nUnderflow");
    }
    else if(last->next==last){
        printf("\n%d is deleted", last->data);
        free(last);
        last=NULL;
    }
    else{
        struct node *ptr;
        for(ptr=last->next; ptr->next!=last; ptr=ptr->next);
        ptr->next=last->next;
        printf("\n%d is deleted", last->data);
        free(last);
        last=ptr;
        
    }
    return last;
}
//NODE COUNTTING
int countnode(struct node *last){
    if(last==NULL){
        return 0;
    }
    else{
        int count=0;
        struct node *ptr=last->next;
        do{
            count++;
            ptr=ptr->next;
        }while(ptr!=last->next);
        return count;
    }
}
//INSERT AT GIVEN POSITION
struct node* inspos(struct node *last){
    int pos, size=countnode(last);
    printf("\nenter position:");
    scanf("%d",&pos);
    if(pos<0||pos>size){
        printf("\nInvalid Position");
    }
    else if(pos==0) return insbeg(last);
    else if(pos==size) return insend(last);
    else{
        int i;
        struct node *n=(struct node*)malloc(sizeof(struct node)), *ptr;
        printf("\nenter data: ");
        scanf("%d", &n->data);
        for(ptr=last->next,i=1; i<pos; i++,ptr=ptr->next);
        n->next=ptr->next;
        ptr->next=n;
        
    }
    return last;
}
//DELETE BY GIVEN POSITION
struct node* delpos(struct node *last){
 int pos, size=countnode(last);
 printf("\nenter position: ");
 scanf("%d",&pos);
  if(pos<0 || pos>=size){
     printf("\nInvalid position");
    }
  else if(pos==0) return delbeg(last);
  else if(pos==size-1) return delend(last);
  else{
     int i;
     struct node *ptr, *del;
      for(ptr=last->next,i=1; i<pos; i++,ptr=ptr->next);
      del=ptr->next;
      ptr->next=del->next;
      printf("\n%d is deleted",del->data);
      free(del);
    }
    return last;
}
//DELETE BY GIVEN DATA
struct node* deldata(struct node *last){
    if(last==NULL){
        printf("\nUnderflow");
        return last;
    }
    int dt;
    printf("\nEnter data to delete: ");
    scanf("%d", &dt);

    struct node *ptr = last->next;
    struct node *prev = last;

    do{
        if(ptr->data == dt){

         // Case 1: Only one node
            if(ptr == last && ptr->next == last){
                printf("\n%d is deleted", ptr->data);
                free(ptr);
                return NULL;
            }
            // Case 2: Deleting first node
            if(ptr == last->next){
                last->next = ptr->next;
            }
            // Case 3: Deleting last node
            else if(ptr == last){
                prev->next = ptr->next;
                last = prev;
            }
            // Case 4: Middle node
            else{
                prev->next = ptr->next;
            }

            printf("\n%d is deleted", ptr->data);
            free(ptr);
            return last;
        }

        prev = ptr;
        ptr = ptr->next;

    } while(ptr != last->next);

    printf("\nData not found");
    return last;
}
//DISPLAYING
void disp(struct node* last){
	if (last==NULL)
		printf("\nEmpty");
	else{
		struct node *ptr=last->next;
		do{
			printf("%d -> ",ptr->data);
			ptr=ptr->next;
		}while(ptr!=last->next);
		printf("...\n");
	}
}
//MENU DRIVEN MAIN FUNC
int main(){
    printf("\n1. Insert at beginning\n2. Insert at ending");
	printf("\n3. Delete from beginning\n4. Delete from ending");
	printf("\n5. Display list\n6. Count nodes\n7. Insert by position");
	printf("\n8. Delete by position\n9. Delete by data\n0. Exit");
    struct node *Last=NULL;
    int ch;
    while(1){
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
              Last=insbeg(Last);
              break;
            case 2:
              Last=insend(Last);
              break;
            case 3:
              Last=delbeg(Last);
              break;
            case 4:
              Last=delend(Last);
              break;
            case 5:
              disp(Last);
              break;
            case 6:
              printf("\nCount: %d", countnode(Last));
              break;
            case 7:
              Last=inspos(Last);
              break;
            case 8:
              Last=delpos(Last);
              break;
            case 9:
              Last=deldata(Last);
              break;
            case 0:
              return 0;
            default:
              printf("\nInvalid choice.");                    
        }
    }
}
