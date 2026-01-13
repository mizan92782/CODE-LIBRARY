
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *newNode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->next = NULL;
  return node;
}

/*
 *
 *
 *
 *
 *
 *
 *
 */

//! Reverselinklist
Node *ReverseList(Node *head)
{

  if (head == NULL || head->next == NULL)
    return head;

  Node *temp = NULL;

  while (head != NULL)
  {

    Node *x = head;
    head = head->next;
    x->next = temp;
    temp = x;
  }
  return temp;
};

Node *ReverseList2(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;

  Node *curr = head;
  Node *rhead = NULL;
  Node *next = NULL;

  while (curr != NULL)
  {
    // keep other element of list
    next = curr->next;

    // add curr node as hadt or reverse list
    curr->next = rhead;
    rhead = curr;

    // make list others part head as curr
    curr = next;
  }

  return rhead;
}

//!  check contan loop in list

bool detectLoop(Node *head)
{

  Node *slow = head;
  Node *fast = head;

  while (slow != NULL || fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }

  return false;
}


//! detect loop and remove:
void removeLoop(Node *head) {
  
    // If list is empty or has only one node without loop
    if (head == nullptr || head->next ==nullptr)
        return;

    Node *slow = head, *fast = head;

    // Move slow and fast 1 and 2 steps ahead respectively.
    slow = slow->next;
    fast = fast->next->next;

    // Search for loop using slow and fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    // If loop exists
    if (slow == fast) {
        slow = head;

        // if it head node ,try to get last node of loop ,or head provius node
        if (slow == fast)
            while (fast->next != slow)
                fast = fast->next;
        else {
              //get previoud of  of loop not by check previous of both pinter node
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // since fast->next is the looping point 
        fast->next = nullptr;
    }
}

//! get middle element
void get_middle_element(Node *head)
{
  Node *fast = head;
  Node *slow = head;

  while (slow && fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  cout << "middle element : " << slow->data << endl;
}

//!============== merge two Sorted list

Node *mergeTwoLists(Node *list1, Node *list2)
{

  Node *temp = NULL;

  if (list1 == NULL)
    return list2;
  if (list2 == NULL)
    return list1;

  if (list1->data < list2->data)
  {
    temp = list1;
    temp->next = mergeTwoLists(list1->next, list2);
  }
  else
  {
    temp = list2;
    temp->next = mergeTwoLists(list1, list2->next);
  }

  return temp;
}

//! =================== remove duplicate from  list
Node *removeDuplicatesSortedlit(struct Node *head)
{
  // code here

  if (head == NULL || head->next == NULL)
    return head;

  Node *temp = head;

  while (head->next)
  {

    if (head->data == head->next->data)
    {
      head->next = head->next->next;
    }
    else
    {
      head = head->next;
    }
  }

  return temp;
}

// ! recusive way unsorted
Node *removeDuplicates(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }

  if (head->data == head->next->data)
  {
    head = removeDuplicates(head->next);
  }
  else
  {
    head->next = removeDuplicates(head->next);
  }

  return head;
}

//! sorted list
Node *removeDuplicatesUnsorted(Node *head)
{
  if (head == nullptr)
    return nullptr;

  unordered_set<int> seen;
  Node *current = head;
  Node *prev = nullptr;

  while (current != nullptr)
  {
    if (seen.find(current->data) != seen.end())
    {
      // Duplicate found, skip current node
      prev->next = current->next;
      delete current; // optional: to free memory
    }
    else
    {
      seen.insert(current->data);
      prev = current;
    }
    current = prev->next;
  }

  return head;
}

bool ispalindrome(Node **left, Node *right)
{

  if (right == NULL)
    return true;

  bool check = ispalindrome(left, right->next);
  bool checkvalue = (*left)->data == right->data;
  cout << check << " --> " << checkvalue << endl;
  (*left) = (*left)->next;

  return check && checkvalue;
}

//! Delete a specific node

// Node** thakeo Node*& ata easy () proyoon hoi na

void DeleteSpecificNode(Node *&head, Node *delNode)
{
  if (head == NULL || delNode == NULL)
    return;

  // 🟢 Case 1: delNode is the head
  if (head == delNode)
  {
    // make to head the next node
    head = head->next;

    // then delete head node
    delete delNode;
    return;
  }

  // 🔵 Case 2: delNode is in middle or end
  Node *prev = head;
  while (prev->next != NULL && prev->next != delNode)
  {
    // get the provious node of deltete node
    prev = prev->next;
  }

  // If delNode not found in list
  if (prev->next == NULL)
    return;

  // delete by jump the next of delnode
  prev->next = delNode->next; // unlink delNode
  delete delNode;
}

//! length of linklist
int length(Node *head)
{
  if (head == NULL)
    return 0;
  return 1 + length(head->next);
}

//! get nth node from tail
// https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/

//* two pointer approch
int getNthFromLast_tp(Node *head, int n)
{

  Node *temp = head;
  Node *temp2 = head;
  while (n--)
  {
    temp = temp->next;
    if (temp == NULL)
      return -1;
  }

  while (temp != NULL)
  {
    temp = temp->next;
    temp2 = temp2->next;
  }

  return temp2->data;
}

//* legnth approch
int getNthFromLast(Node *head, int n)
{
  // length is short than expectation
  int i = length(head);
  if (i < n)
    return -1;

  Node *temp = head;

  int k = 0;
  while (temp != NULL)
  {

    if (k == i - n)
      break;
    k++;
    temp = temp->next;
  }

  return temp->data;
}

void printList(Node *temp)
{

  while (temp)
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "NULL";
}

//! intersection of list
//* two pointer approch
int intersectPoint(Node *head1, Node *head2)
{

  Node *one = head1;
  Node *two = head2;

  while (1)
  {

    if (one == NULL && two == NULL)
      return -1;

    if (one == two)
    {
      return one->data;
    }

    if (one == NULL)
    {
      one = head2;
    }

    if (two == NULL)
    {
      two = head1;
    }

    one = one->next;
    two = two->next;
  }
}







//! pairwise swap
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



int main()
{

  Node *head = newNode(1);
  head->next = newNode(2);
  head->next->next = newNode(3);
  head->next->next->next = newNode(2);
  head->next->next->next->next = newNode(1);

  // cout<<ispalindrome(&head,head);
  // DeleteSpecificNode(head, head->next->next->next->next);
  // printList(head);

  // cout<<getNthFromLast_tp(head,3);

  return 0;
}