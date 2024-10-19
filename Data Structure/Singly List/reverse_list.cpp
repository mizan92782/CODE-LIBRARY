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

Node* reverseList1(Node* head)
{
     if(head==NULL) return NULL;
      
   
     Node* temp=NULL;
     while (head!=NULL)
     {
        
         Node* x= head;
         head=head->next;

        
         x->next=temp;
         temp=x;

        
     }

   return temp;
     
}



Node* reverseList(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    // reverse the rest of linked list and put the first element at the end 
    Node* rest = reverseList(head->next);
  
      // Make the current head as last node of remaining linked list
    head->next->next = head;

      // Update next of current head to NULL
    head->next = NULL;

       // Return the reversed linked list
    return rest;
}









Node* Rev(Node* head)
{
    if(head == NULL || head->next == NULL) 
        return head;

    Node* temp = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    return prev;
}

    

int main()
{

       //https://www.geeksforgeeks.org/reverse-a-linked-list/
       Node* head=NULL;
       
       for(int i=1;i<=20;i++)
       {
          insertBack(&head,i);
       }


        /*
       deletionFront(&head);
       deletionFront(&head);

       */


       //!if return pointer  
       head=Rev(head);
       printlist(head);



      


}