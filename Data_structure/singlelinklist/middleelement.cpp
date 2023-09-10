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




void get_middle_element(Node* head)
{
     Node* fast=head;
     Node* slow=head;   
      
        
        while(slow && fast && fast->next)
        {    
            slow=slow->next;
            fast=fast->next->next;
            
        }


        cout<<"middle element : "<< slow->data<<endl;
        
}


int main()
{

       /*
          https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
          another appraoch:
          1.vector<Node*> and size/2
          2.get length and legth/2;
       */
       Node* head=NULL;
       
       for(int i=1;i<=10;i++)
       {
          insertBack(&head,i);
       }


        printlist(head);
        get_middle_element(head);


      


}