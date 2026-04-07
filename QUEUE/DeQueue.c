//Write a program to impliment a Double Ended Queue of 5 size using a global array structure.


#include <stdio.h>
#define size 5
int dq[size], f=-1, r=-1;
void pushfront(){
    if((r+1)%size==f){
        printf("\nOverflow");
    }
    else{
        if(f==-1){
            f=r=0;
        }
        else if(f==0){
            f=size-1;
        }
        else{
            f--;
        }
        printf("\nEnter data: ");
        scanf("%d", &dq[f]);
    }
}
void pushrear(){
    if((r+1)%size==f){
        printf("\nOverflow");
    }
    else{
        if(r==-1){
            f=r=0;
        }
        else if(r==size-1){
            r=0;
        }
        else{
            r++;
        }
        printf("\nEnter data: ");
        scanf("%d", &dq[r]);
    }
}
void popfront(){
    if(f==-1){
        printf("\nUnderflow");
    }
    else{
        printf("\n%d deleted",dq[f]);
        if(f==r){
           f=r=-1;
        } 
        else if(f==size-1){
            f=0;
        }
        else{
            f++;
        }
    }
}
void poprear(){
    if(f==-1){
        printf("\nUnderflow");
    }
    else{
        printf("\n%d deleted",dq[r]);
        if(f==r){
            f=r=-1;
        }
        else if(r==0){
            r=size-1;
        }
        else{
            r--;
        }
    }
}
void disp(){
    if(f==-1){
        printf("\nEmpty!!");
    }
    else{
        for(int i=f; i!=r; i=(i+1)%size){
            printf("%d-> %d\t",i,dq[i]);
        }
        printf("%d-> %d\t",r,dq[r]);
    }
}
int main(){
    printf("1.pushfront\n 2.pushrear\n 3.popfront\n 4.poprear\n 5.display\n 0.exit\n");
    while(1){
        int ch;
        printf("\nenter choice: ");
        scanf("%d", &ch);
         if(ch==1) pushfront();
        else if(ch==2) pushrear();
        else if(ch==3) popfront();
        else if(ch==4) poprear();
        else if(ch==5) disp();
        else if(ch==0) break;
        else printf("\nInvalid choice!!");   
    } 
}