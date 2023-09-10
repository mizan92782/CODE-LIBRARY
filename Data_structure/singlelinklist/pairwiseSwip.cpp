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


// !very very importaint code for recursively back to head in a linkedist
Node* pairWiseSwap(struct Node* head) 
    {   
       if(head==NULL || head->next==NULL) return head;
       
       //* storing head->next ,because after recusive head->next=head->next->next ,and head->next will cut
       Node* second=head->next;
       // * in below line: head->next=pawiwiseswip(next-next),because after swap head-next=head->next->next;
       head->next=pairWiseSwap(head->next->next);

       //* linking seccon node to head;
       second->next=head;
       
       return second;
    }












int main()
{

       //https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1
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
       head=reverseList1(head);
       printlist(head);



      


}