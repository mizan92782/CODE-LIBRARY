#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void createNewNode(Node **head, int data)
{
    if (*head == NULL)
    {
        *head = new Node(data);
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new Node(data);
}

bool PalindromeUtil(Node **first, Node *last)
{

    if (last == NULL)
        return true;

    bool isp = PalindromeUtil(first, last->next);
    cout << "* "
         << " == " << (*first)->data << endl;

    if (isp == false)
    {
        return false;
    }

    bool isequal = (*first)->data == last->data;
    (*first) = (*first)->next;

    return isequal;
}

bool isPalindrome(Node *head)
{
    return PalindromeUtil(&head, head);
}

void PrintList(Node *head)
{
    cout << "List :  -> ";
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl
         << endl;
}

void segregate(Node **head)
{
    Node *temp = *head;

    Node *evenStart=NULL;
    Node *evenEnd=NULL;

    Node *oddStart=NULL;
    Node *oddEnd=NULL;

    while (temp != NULL)
    {

        if (temp->data % 2 == 0)
        {
            if (evenEnd == NULL)
            {
                evenEnd = temp;
                evenStart = evenEnd;
            }
            else
            {
                evenEnd->next = temp;
                evenEnd = evenEnd->next;
            }
        }
        else
        {

            if (oddEnd == NULL)
            {
                oddEnd = temp;
                oddStart = oddEnd;
            }
            else
            {
                oddEnd->next = temp;
                oddEnd = oddEnd->next;
            }
        }

        temp = temp->next;

        /* code */
    }


    evenEnd->next=oddStart;
    oddEnd->next=NULL;
    *head=evenStart;
}


 Node* reverse(Node* head) {
   
     Node* cur=head;
     Node* curNext=NULL;
     Node* prev=NULL;


     while (cur!=NULL)
     {
         curNext=cur->next;
         cur->next=prev;
         
         prev=cur;
         cur=curNext;
         
     }


     return prev;
     
}


Node* ReverseIn_Group(Node* head,int k)
{
     int count=0;

     Node* cur=head;
     Node* curNext=NULL;
     Node* prev=NULL;

     while(cur!=NULL && count<k)
     {
         curNext=cur->next;
         cur->next=prev;
         prev=cur;

         cur=curNext;
         count++;
     }

     if(cur!=NULL)
     {
        head->next= ReverseIn_Group(cur,k);
        // because head node is now  last node of k nodes;
     };

     return prev;
}


int main()
{
    Node *head = NULL;
    createNewNode(&head, 1);
    createNewNode(&head, 2);
    createNewNode(&head, 3);
    createNewNode(&head, 4);
    createNewNode(&head, 35);
    createNewNode(&head, 22);
    createNewNode(&head, 16);
    createNewNode(&head, 13);
    createNewNode(&head, 18);
    PrintList(head);
     head=ReverseIn_Group(head,4);
        PrintList(head);

    return 0;
}