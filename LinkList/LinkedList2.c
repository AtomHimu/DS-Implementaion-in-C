#include<stdio.h>
#include<stdlib.h>
int insertAtEnd();
int deleteFromEnd();
int displayList();
int searching();
int insertAtBeg();
int insertAtPos(int pos);
int deleteAtPos(int pos1);
int checkLength();

typedef struct LinkedList{
  int data;
  struct LinkedList *next;
}List;

// Global variables
 List *head=NULL,*last=NULL;

void main(){
    int choice,status;
    while(1){
        printf("\n\n1.Insert at end");
        printf("\n2.Delete from end");
        printf("\n3.Display List");
        printf("\n4.Exit");
        printf("\n5.Search for a element");
        printf("\n6.Insert at beg");
        printf("\n7.Insert at any position");
        printf("\n8.Delete at any position");
        printf("\n9.check Length");
        printf("\n Enter your choice-:");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            status = insertAtEnd();
            if(status == 1){
                printf("\nData inserted successfully");
            }else{
              printf("\nData can't be inserted");
            }
            break;
        case 2:
            status = deleteFromEnd();
            if(status == 1){
                printf("\nData deleted successfully");
            }else{
              printf("\nList is empty");
            }
            break;
        case 3:
            status = displayList();
            if(status == 1){
                printf("\nDisplayed successfully");
            }else{
              printf("\nList is empty");
            }
            break;

        case 4:
            exit(0);
        case 5:
            status = searching();
            if(status == 1){
                printf("\nSearched element successfully");
            }
            else if(status==2){
                printf("\nElement is not present in the List");
            }
            else{
              printf("\nList is Empty");
            }
            break;
         case 6:
            status = insertAtBeg();
            if(status==2){
                printf("\nElement is inserted as First Element successfully");
            }
            else{
              printf("\nElement inserted at beginning successfully");
            }
            break;
         case 7:
             int pos;
             printf("Enter position-:");
             scanf("%d",&pos);
             if(pos>0&&pos<=checkLength()+1){
            status = insertAtPos(pos);
            if(status==0){
              printf("\nYour entered wrong position(your position exceeds length of linkedList");
            }
            if(status==2){

                printf("\nElement is inserted as First Element successfully");
            }
            else{
              printf("\nElement inserted at pos =%d",pos);
            }
             }
             else{
                printf("\nPlease enter valid position");

             }
            break;
        case 8:
             int pos1;
             printf("Enter position-:");
             scanf("%d",&pos1);
             if(pos1>0&&pos1<=checkLength()){
            status = deleteAtPos(pos1);
            if(status==0){
              printf("\nList is empty");
            }
            else{
                    printf("\n successfully deleted element");
            }
             }
             else{
                 printf("\nPlease enter valid position");
             }

            break;
        case 9:
            if(checkLength()==0)
                printf("\nList is empty");
            else{
                printf("\nLength -: %d",checkLength());
            }
            break;
        default:
            printf("You made wrong choice");

        }
    }
}
int checkLength(){

  if(head==NULL)
     return 0;
 else{

    List *temp=head;
    int count=1;
    while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
  }
}
int insertAtEnd(){
    List *newnode;
    newnode=(List*)malloc(sizeof(List));
    if(newnode==NULL)
        return 0;
    int data;
    printf("\nEnter data-:");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=NULL;

    if(head==NULL){
        head=last=newnode;
    }
    else{
        last->next=newnode;
        last=newnode;
    }
    return 1;
}


int deleteFromEnd(){
   if(head==NULL)
      return 0;

   else{
     List *temp,*prev;
     temp=head;
     while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
     }
     // if temp will be equal to head
     if(temp==head){
        printf("\nDeleted element-: %d",temp->data);
        free(temp);
        head=NULL;
        return 1;
     }
    printf("\nDeleted element-: %d",temp->data);
    prev->next=NULL;
     last=prev;
     free(temp);
     return 1;
   }

}

int displayList(){
    if(head==NULL)
        return 0;

    else{
        List *temp=head;
        printf("\n\nData -: ");
        while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
    }
return 1;
}

int searching(){
if(head==NULL)
    return 0;
else{
    int data;
    List *temp=head;
    printf("Enter element for searching-:");
    scanf("%d",&data);
    int count=0;
    while(temp!=NULL){
            count++;
        if(temp->data==data){
            printf("\nSearched element position is=%d",count);
            return 1;

        }
        temp=temp->next;
    }
    return 2;
}

}

//insert at beg
int insertAtBeg(){
   if(head==NULL){
     insertAtEnd();
     return 2;
   }else{
      List *newnode;
      newnode = (List*)malloc(sizeof(List));
      printf("Enter data-:");
      scanf("%d",&newnode->data);
      newnode->next=head;
      head=newnode;
      return 1;
    }
}

//insert at any pos
int insertAtPos(int pos){
    if(head==NULL && pos==1){
     insertAtEnd();
     return 2;
  }
  else if(pos==1){
    insertAtBeg();
    return 2;
  }
  int count =1;
  List *temp=head,*temp1;
  while(count<pos){
        temp1=temp;
    temp=temp->next;
    count++;
  }
  List *newnode;
  newnode = (List*)malloc(sizeof(List));
  printf("Enter data-:");
  scanf("%d",&newnode->data);

  temp1->next=newnode;
  newnode->next=temp;
  return 1;
}
//insert at any pos
int deleteAtPos(int pos){
    if(head==NULL){
        return 0;
    }

    else if(pos==1){
        List *temp=head;
        printf("Deleted element :%d",temp->data);
        head=temp->next;
        return 1;

    }

  int count =1;
  List *temp=head,*temp1;
  while(count<pos){
        temp1=temp;
    temp=temp->next;
    count++;
  }
   //now here deleting element
   printf("\nelement of pos %d is -: %d deleted",pos,temp->data);

   temp1->next=temp->next;
  return 1;
}
