#include <bits/stdc++.h>
using namespace std;

// Node structure for a singly linked list
struct Node {
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

int main() {

    // *------------------------------*
    // *        Node* head            *
    // *------------------------------*
    // A pointer to the first node of the list.
    Node* head = new Node(10);  // head points to first node

    // *------------------------------*
    // *        *head (dereference)   *
    // *------------------------------*
    // Dereferencing head gives a copy of the node (not a reference).
    // Changes to this copy will NOT affect the original node.
    Node nodeObj = *head; // actual node is copied
    cout << nodeObj.val << endl;

    // Change the original node
    head->val = 40;

    cout << "Copy node:" << endl;
    cout << nodeObj.val << endl;  // still shows 10 (copy is not changed)
    cout << head->val << endl;    // shows 40 (original changed)
    cout << "Memory address:" << endl;
    cout << head << " : " << &nodeObj << endl;
    cout << "Memory addresses are different." << endl;

    cout << "\n\n";

    // *------------------------------*
    // *     Shallow copy (pointer)   *
    // *------------------------------*
    // scopy is a shallow copy — it points to the same node as head.
    // Any change through scopy affects the same node.
    cout << "Shallow copy reference (modification):" << endl;
    Node* scopy = head;

    scopy->val = 33;
    cout << scopy->val << endl;
    cout << head->val << endl;
    cout << "Memory addresses are the same:" << endl;
    cout << head << " : " << scopy << endl << endl;

    /*
     * Why is this useful?
     * --------------------
     * - This allows multiple pointers to the same node.
     * - Changing one affects all — because they point to the same memory.
     * - However, if head is reassigned, scopy still points to the old node.
     */

    // Change head to a new node
    Node* newNode = new Node(123343);
    newNode->next = head;
    head = newNode;

    cout << "After reassigning head (scopy unaffected):" << endl;
    cout << "head->val = " << head->val << endl;       // 123343
    cout << "scopy->val = " << scopy->val << endl;     // 33
    cout << "Now memory addresses are different:" << endl;
    cout << head << " : " << scopy << endl;

    cout << "\n\n";

    // *------------------------------*
    // *     Pointer to pointer (**head) *
    // *------------------------------*
    // 'deep' stores the address of head itself.
    // This allows both:
    //  - Accessing/modifying the same node
    //!  - Reassigning head from another scope (e.g., a function)
    cout << "Pointer to pointer (Node** deep):" << endl;
    Node** deep = &head;

    cout << "(*deep)->val = " << (*deep)->val << endl;
    cout << "head->val = " << head->val << endl;
    cout << "deep (address of head): " << deep << " | head: " << head << endl;

    cout << "Changing value through head:" << endl;
    head->val = 444;
    cout << "head->val = " << head->val << endl;
    cout << "(*deep)->val = " << (*deep)->val << endl;

    cout << "Changing value through deep pointer:" << endl;
    (*deep)->val = 999;
    cout << "head->val = " << head->val << endl;
    cout << "(*deep)->val = " << (*deep)->val << endl;

    /*
     * Why use Node** ?
     * -----------------
     * - Allows changing the head pointer itself from inside a function.
     * - Enables advanced memory and pointer manipulation.
     * - Needed when passing linked list head by reference.
     */

    cout << "\nAfter changing head again (deep still tracks it):" << endl;

    Node* newNode2 = new Node(888);
    newNode2->next = head;
    head = newNode2;

    cout << "head->val = " << head->val << endl;        // 888
    cout << "(*deep)->val = " << (*deep)->val << endl;  // 888
    cout << "deep = " << deep << " | head = " << head << endl;

    return 0;
}
