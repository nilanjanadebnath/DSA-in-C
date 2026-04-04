//Write a program to impliment a Normal Queue of 5 size using a global array structure.

#include<stdio.h>
#define size 5
int queue[size], rear=-1;
void push()
{
  if(rear==size -1){
    printf("\noverflow");
  }
  else{
    printf("\nenter data: ");
    scanf("%d", &queue[++rear]);
  }
}
void pop()
{
  if(rear==-1){
    printf("\nunderflow");
  }
  else{
    printf("\n%d deleted", queue[0]);
    for(int i=1; i<=rear; i++){
      queue[i-1]=queue[i];
    }
    rear--;
  }
}
void disp()
{
  if(rear==-1){
    printf("\nempty");
  }
  else{
    for(int i=0; i<=rear; i++){
      printf("%d\t", queue[i]);
    }
  }
}
int main(){
  printf("\n1.push\n2.pop\n3.disp\n0.exit");
  while(1){
    int ch;
    printf("\nenter choice: ");
    scanf("%d",&ch);
    if(ch==1) push();
    else if(ch==2) pop();
    else if(ch==3) disp();
    else if(ch==0) break;
    else{
      printf("\ninvalid choice.");
    }
  }
}
