
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




// ! recusive way
Node *removeDuplicates(Node *head)
{
     if(head==NULL || head->next==NULL)
     {
          return head;
     }
     
     
     if(head->data==head->next->data)
     {
         head=removeDuplicates(head->next);
     }else
     {
         head->next=removeDuplicates(head->next);
     }
     
     
     return head;
}