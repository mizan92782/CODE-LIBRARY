
#include <bits/stdc++.h>
using namespace std;

//!  linklist implementtaion
struct Node
{
  int data;
  Node *right;
  Node *left;
};

Node *createNewNode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->left = node->right = NULL;

  return node;
}

//! ============ Array representation
void InorderArray(vector<int> &tree, int parent)
{
  if (parent >= tree.size())
    return;
  InorderArray(tree, 2 * parent + 1); // left child
  cout << tree[parent] << " ";        // current node
  InorderArray(tree, 2 * parent + 2); // right child
}

void preorderArray(vector<int> &tree, int parent)
{
  if (parent >= tree.size())
    return;
  // left child
  cout << tree[parent] << " ";
  preorderArray(tree, 2 * parent + 1); // current node
  preorderArray(tree, 2 * parent + 2); // right child
}

void PrintLevelByLevel(vector<int> &tree, int parent)
{
  queue<int> que;
  que.push(parent);

  while (!que.empty())
  {
    int levelSize = que.size(); // number of nodes in current level

    for (int i = 0; i < levelSize; ++i)
    {
      int x = que.front();
      que.pop();

      if (x == -1)
      {
        cout << "null" << " ";
      }
      else
      {
        cout << tree[x] << " ";
      }

      // Push left and right children
      if (2 * x + 1 < tree.size())
        que.push(2 * x + 1);
      if (2 * x + 2 < tree.size())
        que.push(2 * x + 2);
    }

    cout << endl; // move to next level
  }
}

//! ============ insertio
void Insertion(Node *&root, int val)
{

  if (root == NULL)
  {
    root = createNewNode(val);
    return;
  }

  queue<Node *> que;

  que.push(root);

  while (!que.empty())
  {
    Node *curr = que.front();
    que.pop();

    if (curr->right == NULL)
    {
      curr->right = createNewNode(val);
      return;
    }

    if (curr->left == NULL)
    {
      curr->left = createNewNode(val);
      return;
    }

    que.push(curr->right);
    que.push(curr->left);
  }
}

//!-------------- change child
// left ->right
// right->left
void mirror(Node *root)
{
  if (root == nullptr)
    return;

  // Recursively process the left
  // and right subtrees.
  mirror(root->left);
  mirror(root->right);

  // swap the left and right nodes.
  Node *temp = root->left;
  root->left = root->right;
  root->right = temp;
}

//! ===========  print order wise tree
void PreOder(Node *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  PreOder(root->left);
  PreOder(root->right);
}

//! ============ print level
//* approch : print by height counting
//! print height or tree
int height(Node *root)
{

  if (root == NULL)
    return 0;
  return 1 + max(height(root->right), height(root->left));
}

//! print a specific level node

void printcurrentLevel(Node *root, int level)
{

  if (root == NULL)
  {
    if (level == 1)
    {
      cout << " NULL "; // left node
    }
    else
    {
      cout << " ___  "; // no parent here for this node
    }
    return;
  }

  if (level == 1)
  {
    cout << root->data << " ";
  }
  else
  {
    printcurrentLevel(root->right, level - 1);
    printcurrentLevel(root->left, level - 1);
  }
}

//! print level order
void printLeverlOrder(Node *root)
{

  int h = height(root);
  for (int i = 1; i <= h; i++)
  {
    printcurrentLevel(root, i);
    cout << endl;
  }
}

//* apprich 2 : print by queue;

void printLevelOrderQueue(Node *root)
{

  queue<Node *> que;
  if (root == NULL)
  {
    cout << " tree is empty";
    return;
  }

  que.push(root);

  while (!que.empty())
  {
    int l = que.size();

    for (int i = 0; i < l; i++)
    {
      Node *node = que.front();
      que.pop();

      cout << node->data << " ";

      if (node->left)
        que.push(node->left);
      if (node->right)
        que.push(node->right);
    }
    cout << endl;
  }
}

vector<vector<int>> levelOrderGetinVertor(Node *root)
{
  if (root == nullptr)
    return {};

  // Create an empty queue for level order traversal
  queue<Node *> q;
  vector<vector<int>> res;

  // Enqueue Root
  q.push(root);
  int currLevel = 0;

  while (!q.empty())
  {
    int len = q.size();
    res.push_back({});

    for (int i = 0; i < len; i++)
    {

      // Add front of queue and remove it from queue
      Node *node = q.front();
      q.pop();

      res[currLevel].push_back(node->data);

      // Enqueue left child
      if (node->left != nullptr)
        q.push(node->left);

      // Enqueue right child
      if (node->right != nullptr)
        q.push(node->right);
    }
    currLevel++;
  }
  return res;
}

//! ======== print spiral

void printcurrentlevel(Node *root, int level, bool spiral)
{

  if (root == NULL)
  {
    return;
  }

  if (level == 1)
  {
    cout << root->data << " ";
  }
  else
  {
    if (spiral == true)
    {
      printcurrentlevel(root->left, level - 1, spiral);
      printcurrentlevel(root->right, level - 1, spiral);
    }
    else
    {

      printcurrentlevel(root->right, level - 1, spiral);
      printcurrentlevel(root->left, level - 1, spiral);
    }
  }
}

//! ============== print Reverse order
// like level order ,just start from deep to root,also can use stack approch
void printLevel(Node *root)
{
  int h = height(root);
  int i;
  for (i = h; i >= 1; i--)
  {
    cout << "level : " << i << " -> ";
    printcurrentlevel(root, i);
    cout << endl;
  }
}

// printcurrnt level,
// its recursively decrese level upto its reah level=1,actullay
// such way,its reach to i level
void printcurrentlevel(Node *root, int level)
{

  if (root == NULL)
  {
    return;
  }

  if (level == 1)
  {
    cout << root->data << " ";
  }
  else
  {
    printcurrentlevel(root->left, level - 1);
    printcurrentlevel(root->right, level - 1);
  }
}

//!--====================================================================   basic problem

//! ----------------------get all node amount
int getSize(Node *node)
{

  if (node == NULL)
    return 0;

  return 1 + getSize(node->right) + getSize(node->left);
};

//!-------------------- find max and min element
int findMax(Node *root)
{

  if (root == NULL)
    return 0;
  int r = findMax(root->right);
  int l = findMax(root->left);

  return max(root->data, max(r, l));
}

int findMin(Node *root)
{

  if (root == NULL)
    return INT_MAX;
  int r = findMin(root->right);
  int l = findMin(root->left);

  return min(root->data, min(r, l));
}
//! ----------------------tree is  sum tre

//* this approach will modify current tree nodes value;
bool isSumTree(Node *root)
{

  /// if leaf node
  if ((root == NULL) || (root->right == NULL && root->left == NULL))
    return true;

  bool l = true;
  bool r = true;
  int lv = 0;
  int rv = 0;

  // check left node or righ node is sumTree and catch value;

  if (root->left != NULL)
  {
    l = isSumTree(root->left);
    lv = root->left->data;
  }

  if (root->right != NULL)
  {
    r = isSumTree(root->right);
    rv = root->right->data;
  }

  // check this node is sumtree
  bool p = root->data == (lv + rv);

  root->data = lv + rv + root->data;

  // return ans;
  return l && r && p;
}
//* this node will not modify tree value;
pair<bool, int> isSumTreeHelper(Node *root)
{
  // Base case: null node
  if (root == NULL)
    return {true, 0};

  // Leaf node is always a sum tree
  if (root->left == NULL && root->right == NULL)
    return {true, root->data};

  auto left = isSumTreeHelper(root->left);
  auto right = isSumTreeHelper(root->right);

  bool isCurrentSumTree = (left.first && right.first && (root->data == left.second + right.second));

  int totalSum = left.second + right.second + root->data;

  return {isCurrentSumTree, totalSum};
}

bool isSumTree1(Node *root)
{
  return isSumTreeHelper(root).first;
}

//! ----------------------- identical tree or same tree
bool isIdentical(Node *r1, Node *r2)
{

  if (r1 == NULL && r2 == NULL)
    return true;

  if ((r1 != NULL && r2 == NULL) || (r1 == NULL && r2 != NULL) || (r1->data != r2->data))
    return false;

  return isIdentical(r1->right, r2->right) && isIdentical(r1->left, r2->left);
}

//!........................ mirror or symantical tree
bool isMirrotTree(Node *r1, Node *r2)
{

  // both nodes are leaf
  if (r1 == NULL && r2 == NULL)
    return true;

  // if anyone leaf or value not same
  if ((r1 != NULL && r2 == NULL) || (r1 == NULL && r2 != NULL) || (r1->data != r2->data))
    return false;

  // get response for chield
  // mirors is likes identical nodes but campare differnt chields
  return isMirrotTree(r1->right, r2->left) && isMirrotTree(r1->left, r2->right);
}
//! using stack
bool isSymmetric(Node *root)
{
  if (root == nullptr)
    return true;

  // Two stacks to store nodes for comparison
  stack<Node *> s1, s2;

  // Initialize the stacks with the left
  // and right subtrees
  s1.push(root->left);
  s2.push(root->right);

  while (!s1.empty() && !s2.empty())
  {

    // Get the current pair of nodes
    Node *node1 = s1.top();
    Node *node2 = s2.top();
    s1.pop();
    s2.pop();

    // If both nodes are null, continue to the next pair
    if (node1 == nullptr && node2 == nullptr)
    {
      continue;
    }

    // If one node is null and the other is not,
    // or the nodes' data do not match
    // then the tree is not symmetric
    if (node1 == nullptr || node2 == nullptr || node1->data != node2->data)
    {
      return false;
    }

    // Push children of node1 and node2 in opposite order
    // Push left child of node1 and right child of node2
    s1.push(node1->left);
    s2.push(node2->right);

    // Push right child of node1 and left child of node2
    s1.push(node1->right);
    s2.push(node2->left);
  }

  // If both stacks are empty, the tree is symmetric
  return s1.empty() && s2.empty();
}

//!.........................cousins  nodes
// not same parent but same lavel
void findSibling(Node *root, int x, int y, int &xl, int &yl, bool &isSibling, int level)
{
  if (root == NULL)
    return;

  //* catch lavel
  if (root->data == x)
    xl = level;
  if (root->data == y)
    yl = level;

  //* check is they sibling
  if (root->left && root->right)
  {
    if ((root->left->data == x && root->right->data == y) ||
        (root->left->data == y && root->right->data == x))
    {
      isSibling = true;
    }
  }

  //* if the sibling that means they not cousing,not need to check next;
  if (isSibling)
    return;

  findSibling(root->left, x, y, xl, yl, isSibling, level + 1);
  findSibling(root->right, x, y, xl, yl, isSibling, level + 1);
}
// Main function to check if two nodes are cousins
bool isCousins(Node *root, int x, int y)
{
  int xl = 0, yl = 0;
  bool isSibling = false;

  findSibling(root, x, y, xl, yl, isSibling, 1);

  return (xl == yl && !isSibling);
}

//!--------------------------perfect biany tree
// no internal node have single child
// all leaf in same lavel
bool isPerfectUtil(Node *root, int level, int &leafLevel)
{
  if (root == NULL)
  {
    return true;
  }

  // If it's a leaf node
  if (root->left == NULL && root->right == NULL)
  {
    if (leafLevel == 0)
    {
      leafLevel = level; // store the level of first leaf
      return true;
    }
    return (level == leafLevel); // check if all leaves are at same level
  }

  // If it's an internal node and one child is missing
  if (root->left == NULL || root->right == NULL)
  {
    return false;
  }

  // Recur for left and right subtree
  return isPerfectUtil(root->left, level + 1, leafLevel) &&
         isPerfectUtil(root->right, level + 1, leafLevel);
}

bool isPerfect(Node *root)
{
  int leafLevel = 0;
  return isPerfectUtil(root, 1, leafLevel);
}

//!~------------------------foldable tree
// subtree structure wise mirror
// value not face ,is subtree structre is  mirror:
bool foldable(Node *a, Node *b)
{
  if (a == NULL && b == NULL)
  {
    return true;
  }

  if (a == NULL || b == NULL)
    return false;

  return foldable(a->right, b->left) && foldable(a->left, b->right);
}
bool IsFoldable(Node *root)
{
  if (root == NULL)
    return true;

  return foldable(root->right, root->left);
}

//! by breathfirst
bool isFoldable(Node *root)
{
  if (root == nullptr)
    return true;

  queue<Node *> q;
  q.push(root->left);
  q.push(root->right);

  while (!q.empty())
  {
    Node *a = q.front();
    q.pop();
    Node *b = q.front();
    q.pop();

    // If both subtrees are null, continue.
    if (a == nullptr && b == nullptr)
      continue;

    // If one of the subtrees is null,
    // return false.
    if (a == nullptr || b == nullptr)
      return false;

    // Push left node of a and right
    // node of b.
    q.push(a->left);
    q.push(b->right);

    // Push right node of b and left
    // node of a.
    q.push(a->right);
    q.push(b->left);
  }

  return true;
}

//!====================== cheack a tree is complete bianry tree
// all nodes are completed from left to riggt
// all nodes in samce lave

// approach: traverse lavel order: if get a node is null then findnull is true
// then if we get any node after set findNULL =true, that means it not completet
//  dnt need to calcute lavel,just find the first nullnode,and check is we get any next null any node
bool isCompleteBinaryTree(Node *root)
{
  if (root == nullptr)
    return true;

  queue<Node *> q;
  q.push(root);
  bool end = false;

  while (!q.empty())
  {
    Node *current = q.front();
    q.pop();

    // Check left child
    if (current->left)
    {
      if (end)
        return false;
      q.push(current->left);
    }
    else
    {

      // If left child is missing,
      // mark the end
      end = true;
    }

    // Check right child
    if (current->right)
    {
      if (end)
        return false;

      q.push(current->right);
    }
    else
    {

      // If right child is missing,
      // mark the end
      end = true;
    }
  }

  return true;
}

//!----------------------- Diameter of a tree
// count maximum of node of tree
// approch:
// 1. count left and right maximum widget and make sum
// 2. trck best width
int diameterRecur(Node *root, int &res)
{

  // Base case: tree is empty
  if (root == nullptr)
    return 0;

  // find the height of left and right subtree
  // (it will also find of diameter for left
  // and right subtree).
  int lHeight = diameterRecur(root->left, res);
  int rHeight = diameterRecur(root->right, res);

  // Check if diameter of root is greater
  // than res.
  res = max(res, lHeight + rHeight);

  // return the height of current subtree.
  return 1 + max(lHeight, rHeight);
}

// Function to get diameter of a binary tree
int diameter(Node *root)
{

  // set inital 0
  int res = 0;
  diameterRecur(root, res);
  return res;
}

//! -----find duplicate to same subtree
set<string> st;
int ans = 0;
string answer(Node *root)
{

  if (root == nullptr)
    return "";

  //find left and right side
  string l = answer(root->left);
  string r = answer(root->right);

  // make final strng of subtree
  string final = l + "." + to_string( root->data )+ '.' + r;


  //check is it alredy get
  if (st.count(final) && final.size() > 3)
  {
    // cout<<final<<endl;
    ans = 1;
  }

  st.insert(final);

  return final;
}

//if i want to get all subtree shoudl store node in a hast:
//then traversing from head we get all duplicate subtree
int dupSub(Node *root)
{

  answer(root);

  return ans;
}

//! populated inorder succesor: https://www.geeksforgeeks.org/populate-inorder-successor-for-all-nodes/



//! ---------------------- inorderSuccessor
// basically to find inorder succesor ,will reversse the inoreder rules
 // reverse rules : right ->root ->left
 //and get previous node by backtracking ,and  get inorder of all nodes
Node* inorderSuccessorUtil(Node* root,int target,Node*& last){
        
        if(root==NULL) return nullptr;


       //step : 1
       // if riht child exist inorder order succesor  always in right chidl
       //get inorder succesor from right child

       Node* succ=inorderSuccessorUtil(root->right,target,last);


       // step 2:
       //if  alrady get succesor return it,it answer
       if(succ) return succ;


        //check for curreent node
       //check here is it is target node then last node will be it ancestor
       if(root->data==target){
        return last;
      }

       // step 4 : upgrade last node ,make current node aslast node before backtrackint
       last=root;


       //step:5 
       //if not get in  right,find in left node

       return inorderSuccessorUtil(root->left,target,last);
  
}


void inorderSuccessor(Node* root,int target){

     //initial node
     Node* last=NULL;
     Node* successor= inorderSuccessorUtil(root,target,last);
     
     cout<<"inorder succesor of : "<<target<<" : ";
     cout<<successor->data<<endl;
}



//! ----------------------get all path:
void dfs(Node* root, vector<int>& currentPath, vector<vector<int>>& allPaths) {
    if (!root) return;

    // Add current node to path
    currentPath.push_back(root->data);

    // If it's a leaf node, store the path
    if (!root->left && !root->right) {
        allPaths.push_back(currentPath);
    } else {
        // Continue DFS
        dfs(root->left, currentPath, allPaths);
        dfs(root->right, currentPath, allPaths);
    }

    // Backtrack
    currentPath.pop_back();
}

// Function to return all root-to-leaf paths
vector<vector<int>> getAllPaths(Node* root) {
    vector<vector<int>> allPaths;
    vector<int> currentPath;
    dfs(root, currentPath, allPaths);
    return allPaths;
}

int main()
{
  // Example binary tree (0-based index)
  //         4
  //       /   \
    //    6     2
  //      / \   / \
    //   6   7 22 11
  //    / \
    // 66 99 ...
  vector<int> tree{4, 6, -1, 6, 7, -1, 1, 11, 66, 99, 13, 63, 65};

  // preorderArray(tree, 0);
  // PrintLevelByLevel(tree, 0);

  //! linklist implementation

  Node *root = createNewNode(2);
  //  Insertion(root,3);
  //  Insertion(root,5);
  //  Insertion(root,23);
  //  Insertion(root,39);
  //  Insertion(root,84);
  //  Insertion(root,4);
  //  Insertion(root,23);
  //  Insertion(root,88);

  root->right = createNewNode(4);
  root->left = createNewNode(12);

  root->right->right = createNewNode(54);
  root->left->left = createNewNode(52);
  root->left->left->right = createNewNode(99);
  root->left->left->left = createNewNode(84);
  root->right->right->left = createNewNode(55);
  root->right->right->right = createNewNode(52);

  // PreOder(root);
  // printLeverlOrder(root);
  //! print a level
 // printcurrentLevel(root, 3);
  printLevelOrderQueue(root);
}