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











int intersectPoint(Node* head1, Node* head2)
{
   
   Node* one=head1;
   Node* two=head2;
   
   
    while(1)
    {
        
          if(one==NULL && two==NULL) return -1;
          
        if(one==two)
        {
            return one->data;
        }
        
        
      
        
        if(one==NULL)
        {
            one=head2;
        }
        
        if(two==NULL)
        {
            two=head1;
        }
        
        
        one=one->next;
        two=two->next;
    }
   
}