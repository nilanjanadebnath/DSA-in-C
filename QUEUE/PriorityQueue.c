//Write a program to impliment a Priority Queue of 5 size using a global array structure.

#include<stdio.h>
#define size 5
struct element{
    int d, pr;
};
int rear =-1;
struct element pq[size];
void push(){
    if(rear==size-1){
        printf("\nOverflow");
    }
    else{
        rear++;
        printf("\nEnter data: ");
        scanf("%d", &pq[rear].d);
        printf("\nEnter prior: ");
        scanf("%d", &pq[rear].pr);
    }
}
int gethigh(){
    int max=0;
    for(int i=1;i<=rear;i++){
        if(pq[i].pr>pq[max].pr){
            max=i;
        }
    }
    return max;
}
int getlow(){
    int min=0;
    for(int i=1;i<=rear;i++){
        if(pq[i].pr<pq[min].pr){
            min=i;
        }
    }
    return min;
}
void pophigh(){
    if(rear==-1){
        printf("\nUnderflow");
    }
    else{
        int del=gethigh();
        printf("\nP%d -> %d is deleted", pq[del].pr, pq[del].d);
        for(int i=del+1;i<=rear;i++){
            pq[i-1] = pq[i];
        }
        rear--;
    }
}
void poplow(){
    if(rear==-1){
        printf("\nUnderflow");
    }
    else{
        int del=getlow();
        printf("\nP%d -> %d is deleted", pq[del].pr, pq[del].d);
        for(int i=del+1;i<=rear;i++){
            pq[i-1] = pq[i];
        }
        rear--;
    }
}
void disp(){
    if(rear==-1){
        printf("\nEmpty");
    }
    else{
        for(int i=0; i<=rear;i++){
            printf("\nP%d -> %d\t", pq[i].pr,pq[i].d);
        }
    }
}
int main(){
    printf("\n1.Push\n2.Pophigh\n3.Poplow\n4.Display\n0.Exit");
    int ch;
    while(1){
        printf("\nenter choice: ");
        scanf("%d",&ch);
        if(ch==1) push();
        else if(ch==2) pophigh();
        else if(ch==3) poplow();
        else if(ch==4) disp();
        else if(ch==0) break;
        else printf("\nInvalid choice!!");
    }
}