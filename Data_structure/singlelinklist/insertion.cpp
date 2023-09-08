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

int main()
{

       Node* head=NULL;
       insertBack(&head,1);
       insertBack(&head,2);
       insertBack(&head,3);
       insertBack(&head,5);
       insertBack(&head,6);
       insertFront(&head,1111);
       insertFront(&head,66);


       printlist(head);

      


}