 #include<bits/stdc++.h>
 using namespace std;
 

struct Node
{
    int data;
    Node* right;
    Node* left;
};


 Node* createNewNode(int data)
{
      Node* node= new Node;
     node->data=data;
     node->left=node->right=NULL;

    return node;
     
}

  /*   
        8
       /  \
      5    33
    /  \    /  \
    4   9   90   74
                 /  \
                55  34
*/


/*
  *this code is very important ,its a ideal code
  * for traverse all path from root to leaf or root to any node path
  * 
  * 
  *  a significant part of this code is
  * v.pop_back(),after going to left->left ...
  * we going to 8 to 34 ,its a path and perform operation
  * after we pop() we return to previos recursive function and got to right***
  * thus we got to 8 to 55..that a path........this is important to understand
  * 
  * 
  * Now .loop part:::
  * if iteratot i=0 to i=n,that meand we conscider root to that node
  * if itereatn i=n to i=0 that means we cocider a path to node  from any parent node
  * 
  * **two example:
  * https://practice.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
  * https://leetcode.com/problems/path-sum-iii/description/
*/

void solve(Node* root,vector<int> v,int &ct,int k){
        if(root == NULL) return ;
        
        v.push_back(root->data);

        solve(root->left,v,ct,k);
        solve(root->right,v,ct,k);

        int n = v.size();
        long long sum = 0;

        for(int i = n - 1;i >= 0;--i){
            sum += v[i];
            if(sum == k)
                ct++;
        }
        v.pop_back();
    }
