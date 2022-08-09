#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


 struct node{
       int data;
       struct node*next;

    };
    struct node*head,*newnode,*temp;

//CREATE A LINKED LIST
void Create(){
    head=0;
    int choice;

    choice=1;
    while(choice==1){
     newnode=(struct node*)malloc(sizeof(struct node));
     printf("\nEnter data-");
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

}
//INSERT AN ELEMENT AT THE BEGINING
void InsertBegin(){
    struct node*beginnode;
    beginnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to be inserted at the begining:");
    scanf("%d",&beginnode->data);

    beginnode->next=head;
    head=beginnode;
}

//INSERT AN ELEMENT AT THE END
void InsertLast(){

   struct node*endnode;
    endnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to be inserted at the end:");
    scanf("%d",&endnode->data);

    endnode->next=0;
    temp=head;

    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=endnode;

}

//INSERT AN ELEMENT IN THE MIDDLE
void InsertGivenLocation(){
    int Pos;
    int i=1;


    struct node*locationnode;
    locationnode=(struct node*)malloc(sizeof(struct node));

     int count;
     temp=head;
     while(temp!=0){
        temp=temp->next;
        count++;
     }

    printf("\n\nEnter the position to be insert:");
    scanf("%d",&Pos);

    if(Pos>count)
        printf("Invalid position");
    else{
     temp=head;
     while(i<Pos-1){
            temp=temp->next;
            i++;
     }

     printf("\nEnter data to be inserted at a given location:");
     scanf("%d",&locationnode->data);

     locationnode->next=temp->next;
     temp->next=locationnode;
    }
}

//DELETE THE FIRST ELEMENT
void DeleteBegin(){
    if(head==0){
        printf("UNDERFLOW CONDITION");
    }
    else{
      temp=head;
      head=head->next;
      free(temp);

    }

}

//DELETE THE LAST ELEMENT
void DeleteEnd(){
    struct node*prevnode;
    if(head==0){
        printf("UNDERFLOW CONDITION");
    }
    else{
       temp=head;

       while(temp->next!=0){
        prevnode=temp;
        temp=temp->next;

     }
     if(temp==head){
        head=0;

     }
     else{
        prevnode->next=0;
      free(temp);
     }

    }



}

//DISPLAY THE LINKED LIST(TRAVERSING THE LIST)
void display(){
     int count;
     temp=head;
     while(temp!=0){
        printf("%d\t\t",temp->data);
        temp=temp->next;
        count++;
     }
}
//SEARCH AN ELEMENT IN THE LINKED LIST
void search(){
   int ele;
   printf("\nEnter the element you want to search:");
   scanf("%d",&ele);
   int found=0;

   temp=head;
   while(temp->next!=0){
    if(temp->data==ele){
        found++;
    }

    temp=temp->next;
   }



    if(found==0){
        printf("\nSEARCH IS UNSUCCESSFULL");
    }
    else{
        printf("\nSEARCH IS SUCCESSFULL");
    }
   }

int main(){

    printf("-------------------------------OPERATIONS OF LINKED LISTS---------------------------------\n");

    bool condition=true;

    while(condition){

     printf("\n\n====>1.Create a linked list\n====>2.Insert an element at the beginning\n====>3.Insert an element at the end\n====>4.Insert an element to the middle\n====.5.Delete the begining element\n====>6.Delete the end element\n====>7.Display the linked list\n====>8.Search an element\n====>9.Exit\n ");
     int option;
     printf("\n\nEnter your option:");
     scanf("%d",&option);



     switch(option){
     case 1:
       Create();
       printf("\nLINKED LIST CREATED:");
       display();
       break;

     case 2:
       InsertBegin();
       printf("\n\n------->LINKED LIST AFTER INSERTING AT THE BEGINNING:");
       display();
       break;

     case 3:
       InsertLast();
       printf("\n\n------->LINKED LIST AFTER INSERTING AT THE END :");
       display();
       break;

     case 4:
        InsertGivenLocation();
        printf("\n\n------->LINKED LIST AFTER INSERTING AT THE MIDDLE:");
        display();
        break;

     case 5:
        DeleteBegin();
        printf("\n\n------->LINKED LIST AFTER DELETING AT THE BEGINING:");
        display();
        break;

     case 6:
         DeleteEnd();
         printf("\n\n------->LINKED LIST AFTER DELETING AT THE END:");
         display();
         break;

     case 7:
        printf("\n\n--------->LINKED LIST:");
        display();


     case 8:
         search();
         break;

     case 9:
        condition=false;
        printf("THANK YOU....BYE!");
        break;

     default:
        printf("INVALID INPUT....TRY AGAIN....");
        break;
    }
    }


    return 0;
}
