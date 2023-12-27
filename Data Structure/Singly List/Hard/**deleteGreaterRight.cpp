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





// !========= Delete node that have greater value in right





Node* deleteNodesOnRightSide(Node* head)
{

    //https://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side/

    // if list=NULL or reach to last node or only one node
    if(head==NULL || head->next==NULL)
    {
        return head;
    }


     // * recusively goint to last node
    // ! this approach is very important********************
    //! how to reach of list and select specific node

    
      Node* nextNode=deleteNodesOnRightSide(head->next);


      // * if right node is great than curr node
      if(nextNode->data > head->data)
      {
        return nextNode;
      }


      // ! ***** current node is greater node and no node greate than it in right side
       
       head->next=nextNode;


    return head;





     
     


}

int main()
{

       Node* head=NULL;
       int arr[]={12,15,10,11,5,6,2,3};
       
       for(int i=0;i<8;i++)
       {
          insertBack(&head,arr[i]);
       }


        
       printlist(head);
       cout<<endl;
       head=deleteNodesOnRightSide(head);
       printlist(head);

     

      


}