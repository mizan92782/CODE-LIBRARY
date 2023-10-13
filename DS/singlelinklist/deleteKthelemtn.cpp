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








/*
  ! import part of the code if use of static int datatype:
  

  */

//* self code
Node* deleteK(Node *head,int K)
{
     static int x=1;
     
 
  
     
  if(head==NULL)
  {   
      x=1;
      // its need when use T test case ,for every testcase need to set x=1;other wise previous test case x will executed
      return head;
  }
  
 
  
  if(x!=0 && K==x)
  {   
      x=1;
      head=deleteK(head->next,K);
      
  }else
  {
       x++;
      head->next=deleteK(head->next,K);
  }
  
  return head;
  
  
}





int main()
{

       //https://www.geeksforgeeks.org/remove-every-k-th-node-linked-list/
       Node* head=NULL;
       
       for(int i=1;i<=20;i++)
       {
          insertBack(&head,i);
       }


       


      


}