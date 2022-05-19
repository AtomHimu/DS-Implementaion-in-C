
#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}Node;

Node *head=NULL , *last=NULL;
//function to insert a node in linked List

void insert(char checker,Node *newNode1){
    Node *temp=head;
    Node *newNode;
    int data;

    newNode =(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
     printf("Memory is full");
     return;}
     if(checker=='I'){
      printf("Enter your data -: ");
      scanf("%d",&newNode->data);
      newNode->prev=NULL;
      newNode->next=NULL;
     }else{
        newNode = newNode1;
     }
     if(head==NULL){
           head=last=newNode;
     }
     else{
         newNode->prev=last;
         newNode->next=NULL;
         last->next=newNode;
         last = newNode;
     }
     printf("Data Successfully inserted");
}

void Display(){
 Node *temp;
 temp= head;
 if(temp==NULL)
  {printf("List is empty !!");
  return;
  }
  else{
      while(temp!=NULL){
          printf("%d ",temp->data);
          temp=temp->next;
      }
  }
  printf("\nSuccessfully displayed");
}

void traverseLast(){
Node *temp;
 temp= last;
 if(temp==NULL)
  {printf("List is empty !!");
  return;
  }
  else{
      while(temp!=NULL){
          printf("%d ",temp->data);
          temp=temp->prev;
      }
  }
  printf("\nSuccessfully displayed");
}

void Delete(){
 Node *temp=head,*prev=NULL;
    if(head==NULL)
     {
     printf("\nList is empty");
     return ;
     }

     if(head->next==NULL){
        printf("\ndeleted item -: %d",temp->data);
        head=last=NULL;
        free(temp);
        return;
     }

          while(temp->next!=NULL){
            prev = temp;
            temp=temp->next;
          }
          prev->next=NULL;
          last = prev;
          printf("\nDeleted item is-: %d",temp->data);
          free(temp);



}

int search(char checker){
    int pos=1;
    Node *temp;
    if(checker=='l')
      temp= last;
     else
       temp=head;
    if(temp==NULL)
  {
      printf("List is empty !!");
    return 0;
  }
    int data;
    printf("Enter item for search-: ");
    scanf("%d",&data);

      while(temp!=NULL){
          if(temp->data==data)
        {  if(checker!='l')
            printf("%d is the position of %d element",pos,temp->data);
        else
            printf("%d is the position from last of %d element",pos,temp->data);
             return 0;
        }
         pos++;
         if(checker=='l')
           temp=temp->prev;
         else
           temp = temp->next;
      }

      return pos;
}


//function to enter at specific position
 void insert_Pos(){
     Node *temp;
     temp=head;
    if(head==NULL){
        printf("\nList is empty !!!");
        return;
    }
    int pos;
    printf("\nEnter pos-:");
    scanf("%d",&pos);

     Node *newNode;
     newNode = (Node *)malloc(sizeof(Node));
     if(newNode==NULL){
        printf("\nMemory is full");
        return;
     }
    printf("Enter your data -:");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    newNode->prev=NULL;
    int count=1;
    Node *temp1;
     while(temp!=NULL){
         if(pos==1){
            newNode->next=head;
            head->prev=newNode;
            newNode->prev=NULL;
             head=newNode;
              printf("Data successfully entered at %d position",pos);
             return;
         }
        if(pos==count){
          temp1->next=newNode;
          newNode->prev=temp1;
          newNode->next=temp;
          printf("Data successfully entered at %d position",pos);
          return;
        }
        temp1=temp;
        temp = temp->next;
        count++;
     }
      //if pos is last;
      if(pos==count){
        insert('p',newNode);
        printf("\n node successfully entered at position %d",pos);
      }

 }

 //function to delete a element from a specific pos
 void delete_Pos(){
     Node *temp=head,*prev=NULL;
    if(head==NULL)
       {
          printf("\nList is empty");
          return;
       }
       printf("\nEnter pos-: ");
       int pos;
       scanf("%d",&pos);
       if(pos<=0){
         printf("\nEnter a valid pos");
         return;
        }
       int count=1;
       if(pos==1){
        head=temp->next;
        printf("\nDeleted item of pos %d -:%d",pos,temp->data);
        free(temp);
        return;
       }

       while(temp!=NULL){
            if(pos==count){
           // prev->next=temp->next;
            //printf("Deleted item of pos %d -: %d",pos,temp->data);
            //return ;
            Delete();
          }
          prev=temp;
          temp= temp->next;

          count++;
       }

       //if pos didn't find means position entered by user is invalid
       printf("\nPlease enter a valid pos");


 }

int main()
{
    int choice,status;
    while(1){
       printf("\n1.Insert\n2.Delete\n3.Display\n4.display from last\n5.search\n6.Search from last\n7.Insert at pos\n8.Delete from specific pos\n9.exit\n");
       printf("Enter your choice -");
       scanf("%d",&choice);
       switch(choice){
           case 1:
            insert('I',NULL);
            break;
            case 2:
            Delete();
            break;
            case 3:
             Display();
             break;
             case 4:
             traverseLast();
            break;
            case 5:
             search('f');
             break;
            case 6:
             search('l');
             break;
            case 7:
                insert_Pos();
                break;
            case 8:
                delete_Pos();
                break;
             case 9:
              exit(1);
            default:
            printf("you made wrong choice");
       }
    }

    return 0;
}
