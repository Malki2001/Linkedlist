#include<stdio.h>
#include<stdlib.h>


 struct node{
       int data;
       struct node*next;

    };
    struct node*head,*newnode,*temp;

void display(){
     int count;
     temp=head;
     while(temp!=0){
        printf("%d\t\t",temp->data);
        temp=temp->next;
        count++;
     }
     printf("\n\n----------->LENGTH OF THE LINKED LIST=%d",count);
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
}
