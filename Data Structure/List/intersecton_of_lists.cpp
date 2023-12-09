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
   !intersection of tow lists
*/
bool present(Node* node,Node* head2);
Node* intersection(Node* head1,Node* head2)
{



    Node* intsNode =NULL;

    // check head1 node compare withe head2 all node
    while(head1)
    {
           if(present(head1,head2))
           {
               insertBack(&intsNode,head1->data);
           }
           head1=head1->next;
    }


 return intsNode;
}

bool present(Node* node,Node* head2)
{
    
     while (head2!=NULL)
     {
        if(head2->data==node->data) return true;
        head2=head2->next;
     }
     
     return false;
}




int main()
{

       /*
          https://www.geeksforgeeks.org/union-and-intersection-of-two-linked-lists/
          also union in this page

         
         
       */
       Node* head1=NULL;
       
       for(int i=1;i<=10;i++)
       {
          insertBack(&head1,i);
       }

       Node* head2= NULL;
        for(int i=5;i<=15;i++)
       {
          insertBack(&head2,i);
       }



        printlist(head1);
        printlist(head2);

        Node* intersectionhead =intersection(head1,head2);
         printlist(intersectionhead);

      


}