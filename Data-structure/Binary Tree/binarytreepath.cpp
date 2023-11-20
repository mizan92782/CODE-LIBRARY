 
 
 /*
 
  ! find all path approach
  ! https://leetcode.com/problems/binary-tree-paths/description/
 
 void func(TreeNode* root,vector<string>& str,string s)
    {
        if(!root)
        return ;
        if(root->left || root->right)
        s += (to_string(root->val) + "->");
        else{
            s += (to_string(root->val));
            str.push_back(s);
        }
        func(root->left, str, s);
        func(root->right, str, s);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>str;

        func(root,str,"");
        return str;

    }
    
    */
