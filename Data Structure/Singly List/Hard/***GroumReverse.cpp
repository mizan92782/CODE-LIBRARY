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



/*
! search recursively
*/


bool search(struct Node* head, int x)
{
    // Base case
    if (head == NULL)
        return false;
 
    // If key is present in current node, return true
    if (head->data == x)
        return true;
 
    // Recur for remaining list
    return search(head->next, x);
}













//!.........................Reverse Gropuwis

Node* ReveseGroup(Node* head,int k)
{
     if(head==NULL) return NULL;


     Node* curr=head;
     Node* Next=NULL;
     Node* prev=NULL;

     int count=0;

     while (curr!=NULL &&  count<k)
     {
             //store next nodt;
             Next=curr->next;
             //making revers
             curr->next=prev;
             prev=curr;

             //find next node in real list
             curr=Next;

             count++;
     }


     //if list not end
     if(Next!=NULL)
     {
         // after reverse this sublist of k lengt head be the last node and its next= null
         // Next is the K+1 node
         head->next=ReveseGroup(Next,k);
     }

          // prev is the head after reverse;
     return prev;
     
}


int main()
{

       Node* head=NULL;
       
       for(int i=1;i<=10;i++)
       {
          insertBack(&head,i);
       }


        
       printlist(head);

       head=ReveseGroup(head,3);
       cout<<endl;
       printlist(head);

      


}