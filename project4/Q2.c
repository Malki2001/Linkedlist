#include<stdio.h>
#include<stdlib.h>

 struct node{
       int data;
       struct node*next;

    };
struct node*head,*previous_node,*current_node,*next_node,*temp,*newnode;

void Reversing(){
   previous_node=0;
   current_node=next_node=head;

   while(next_node!=0){
    next_node=next_node->next;
    current_node->next=previous_node;
    previous_node=current_node;
    current_node=next_node;
   }
   head=previous_node;
}
void display(){
    temp=head;
     while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
     }
}

void main(){

    head=0;
    int choice;
    int count=0;

    choice=1;
    while(choice==1){
     newnode=(struct node*)malloc(sizeof(struct node));
     printf("Enter data-");
     scanf("\t\t%d",&newnode->data);
     newnode->next=0;

     if(head==0)
        head=temp=newnode;
     else{
        temp->next=newnode;
        temp=newnode;
     }
     printf("Do you want to continue(0,1)?-");
     scanf("\t\t%d",&choice);
    }
    printf("\n\n--------->LINKED LIST:");
    display();

    Reversing();
    printf("\n\n--------->REVERSED LINKED LIST:");
    display();



}


