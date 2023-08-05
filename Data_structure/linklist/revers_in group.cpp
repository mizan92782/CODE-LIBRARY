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


 Node* reverse(Node* head, int k) {
    Node* one = NULL;
    Node* two = NULL;
    stack<Node*> sta;

    int x = 0;
    while (head != NULL) {

        Node* hnext=head->next;
        /*This is important,bcos,jokhon stack thake top naoya hobe tokhon top node sathe onno
        gular reversse korle segula aber top noder next node hoya jaba ,kintu agula previous node,tai top noder ager node aber next node hoya
        jabe ,, exp:  1->3->5->8->99
                         k=4;
                    now : head and top 8;
                    reverse : 8->5->3->1
                    so.  akhon next node hobe 5,kintu hoyer kotha 99;
                    tai next node =99;
                    kore rakhte hobe
               */
        if (x < k) {
            sta.push(head);
            x++;
        }

        if (x >= k || hnext==NULL) {
            x = 0;

            while (!sta.empty()) {
                Node* temp = sta.top();
                temp->next=NULL;
                /* this is also importan : karon node gula next node hular sathe connectted,tai alada na kore join dile
                pura list tai add hoya jabe*/
                sta.pop();

                if (one == NULL) {
                    one = new Node(temp->data);
                    two = one;
                } else {
                    one->next = temp;
                    one = one->next;
                }
            }
        }

        head = hnext;
        cout<<"h";
        
    }

    return two;
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
     head=reverse(head,4);
        PrintList(head);

    return 0;
}