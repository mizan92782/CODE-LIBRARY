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
  * ************* palindrome

*/



bool isp(Node** left,Node* right)
    {
          if(right==NULL)
          {
              return true;
          }
          
          bool check=isp(left,right->next);
          
          if(check==false) return false;
          
           check =((*left)->data==right->data);
        
         *left=(*left)->next;
         return check;
}

    bool isPalindrome(Node *head)
    {
       return isp(&head,head);
    }


int main()
{

       /*
          https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
       */
       Node* head=NULL;
       
       for(int i=1;i<=10;i++)
       {
          insertBack(&head,i);
       }


        printlist(head);
      


}