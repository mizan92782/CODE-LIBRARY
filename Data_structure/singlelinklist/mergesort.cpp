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
!! merge sort...............................
*/

void splitingList(Node** a,Node** b,Node* head)
{
    Node*  slow=head;
    Node* fast=head;
    Node* prev=slow;

    while(fast && fast->next)
    {
        // for case : 1->2 
        // we need to store prev node
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
      
        
    }

    // second half head;
    *b=slow;
    //first half head;
    *a=head;
    
    // making last node of first half null;
    prev->next=NULL;

    

    


}



Node* sortList(Node* a,Node* b)
{
     Node* head=NULL;

     if(a==NULL)
     {
        return b;
     }else if(b==NULL)
     {
        return a;
     }

     if(a->data<= b->data)
     {
        head=a;
        head->next=sortList(a->next,b);
     }else{
        head=b;
        head->next=sortList(a,b->next);
     }


    return head;

}





Node*  mergeSort(Node* headref)
{
      if(headref==NULL || headref->next==NULL)
      {
        return headref;
      }


      // for spliting list in two half;
      Node* a;
      Node* b;



     // ! splilint list in a, b two half
      splitingList(&a,&b,headref);

    // ! again and again splilitlist until size 1
   a=mergeSort(a);
   b=mergeSort(b);




    // ! Now add and sorf list;
    // ! in every mergeSort() funtion sorting ther current list 
    // storing head of soritn ling in head ref
       headref=sortList(a,b);
    

 return headref;

}

int main()
{

       /*
         https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
         https://www.geeksforgeeks.org/merge-sort-for-linked-list/
         
         
       */
       Node* head=NULL;
       
       insertBack(&head,4);
       insertBack(&head,1);
       insertBack(&head,14);
       insertBack(&head,44);
       insertBack(&head,34);
       insertBack(&head,88);
       insertBack(&head,12);
       insertBack(&head,12);
       insertBack(&head,12);


       printlist(head);

       head=mergeSort(head);
        printlist(head);

      


}