#include <bits/stdc++.h>
using namespace std;

struct Node
{

    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = this->prev = NULL;
    }
};

//! push element in front
void pushFront(Node **head, int data)
{
    Node *newNode = new Node(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;

    (*head) = newNode;
}

//! push element in back
void pushBack(Node **head, int data)
{
    Node *newNode = new Node(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

//! Delete node   =========================;

void DeleteNode(Node **head, int k)
{
    Node *temp = *head;

    if (temp == NULL)
        return;

    while (temp != NULL)
    {
        bool del = false;

        // if find node--->

        if (temp->data == k)
        {
            // if node is head and it also multyple time delete node
            if (temp->prev == NULL)
            {
                *head = temp->next;

                // ! *** now if *head==NULl ,we can not have prev or nex
                if (*head != NULL)
                {
                    (*head)->prev = NULL;
                }

                delete temp;

                // updare for delete multiply time
                temp = *head;
            }
            else if (temp->next == NULL)
            {
                //! if its last node
                temp->prev->next = NULL;
                delete temp;
                break; // ! No need to traverse further
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                // make temp=temp->prev;as temp will be delete
                temp = temp->prev;
            }
        }
        else
        {
            // Move to the next node
            temp = temp->next;
        }
    }
}

//! Reverse Double list ==================>
/*
https://www.geeksforgeeks.org/reverse-a-doubly-linked-list/

* Approach:
    1.usind stack
    2.using iteration and pointer changing
*/

Node *reverseDLL(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *Curr = head;
    Node *P = NULL;
    Node *N;

    while (Curr)
    {

        N = Curr->next;

        // prev will next;
        Curr->next = P;

        // next will be prev
        Curr->prev = N;

        if (P)
        {
            P->prev = Curr;
        }

        // current node will be prev node in next strp
        P = Curr;

        // forward iteraton
        Curr = N;
    }

    return P;
}

void PrintList(Node *head)
{
    cout << "Printing Doubly list :  ";
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n\n";
}

int main()
{
    // https://www.geeksforgeeks.org/doubly-linked-list-meaning-in-dsa/?ref=appendix

    Node *head = NULL;
    pushFront(&head, 1);
    pushFront(&head, 2);
    pushFront(&head, 3);
    pushFront(&head, 5);
    pushFront(&head, 10);
    pushFront(&head, 10);
    pushFront(&head, 8);
    pushFront(&head, 10);
    pushFront(&head, 10);

    pushBack(&head, 10);

    PrintList(head);
    DeleteNode(&head, 10);
    PrintList(head);
}