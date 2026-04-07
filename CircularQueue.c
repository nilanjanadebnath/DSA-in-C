//Write a program to impliment a Circular Queue of 5 size using a global array structure.

#include<stdio.h>
#define size 5
int cq[size], f=-1, r=-1;
void push(){
    if((r+1)%size==f){
        printf("\nOverflow.");
    }
    else {
        if(f==-1){
        f=0;
        }
        r = (r+1)%size;
        printf("\nenter data: ");
        scanf("%d", &cq[r]);
    }
 }
void pop(){
    if(f==-1){
        printf("\nUnderflow.");
    }
    else if(f==r){
        printf("\n%d deleted.",cq[f]);
        f=r=-1;
    }
    else{
        printf("\n%d deleted.",cq[f]);
        f=(f+1)%size;
    }
}
void disp(){
    if(f==-1){
        printf("\nEmpty.");
    }
    else{
        for(int i=f; i!=r; i=(i+1)%size){
            printf("%d-> %d\t",i, cq[i]);
        }
        printf("%d -> %d",r, cq[r]);
    }
}
int main(){
    printf("1.PUSH\n 2.POP\n 3.DISPLAY\n 0.EXIT\n");
    while(1){
        int ch;
        printf("\nenter choice: ");
        scanf("%d", &ch);
        if(ch==1) push();
        else if(ch==2) pop();
        else if(ch==3) disp();
        else if(ch==0) break;
        else printf("\nInvalid Choice!!");
    }
}
