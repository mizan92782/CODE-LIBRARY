#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
};

Node* newNode(int data)
{
     Node* node = new Node;
     node->data=data;
     node->next=NULL;
return node;
}




void insertFront(Node** head,int data)
{
     Node* node = newNode(data);
     node->next =*(head);
     *(head)=node;
}





void insertBack(Node** head,int data)
{
     
     if(*(head)==NULL)
     {
         *(head)= newNode(data);
        return ;
     }

     // temp age create kore jabe na ,karon tokhon head=null 
     //thake,null asssing not possitble
     Node* temp=*head;

     while (temp->next!=NULL)
     {
        temp=temp->next;
     }

     temp->next = newNode(data);
     
}


void printlist(Node* head)
{
    cout<<"list elemnent :  ";
    while (head!=NULL)
    {
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<endl<<endl;
    
}






 /*
   !deletion linklist
  */


  void deletionFront(Node** head)
  {
     Node* temp=*head;
     (*head)=(*head)->next;

     delete(temp);
  }



 void deletoionBack(Node** head)
 {
     if((*head)==NULL)
     {
        return ;
     }

     Node* temp=*head;
     Node* prev=NULL;

      while (temp->next!=NULL)
      {     
           // ! important 
           prev=temp;
           temp=temp->next;
      }

      prev->next=NULL;

    
      
 }



// *delele even node recursively
void deleteNode(Node** head)
{
    // Base case: If the list is empty, return.
    if (*head == NULL)
    {
        return;
    }

    // Check if the current node's data is even.
    if ((*head)->data % 2 == 0)
    {
        // If it's even, we'll delete this node.
        Node* temp = *head;
        *head = (*head)->next;
        free(temp); // Free the memory of the deleted node.
        deleteNode(head); // Recursively check the next node.
    }
    else
    {
        // If it's not even, move to the next node.
        deleteNode(&((*head)->next));
    }
}


int main()
{

       Node* head=NULL;
       
       
       for(int i=1;i<=20;i++)
       {
          insertBack(&head,i);
       }


        /*
       deletionFront(&head);
       deletionFront(&head);

       */
        
        deleteNode(&head);
       printlist(head);

      


}