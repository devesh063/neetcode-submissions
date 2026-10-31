/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root)
          return root;

        if(root == p || root == q)
          return root;
        
        TreeNode *left = nullptr, *right = nullptr;

        if(p->val < root->val && q->val < root->val)
          left = lowestCommonAncestor(root->left,p,q);
        if(p->val > root->val && q->val > root->val)
          right = lowestCommonAncestor(root->right,p,q);

        if(left)
          return left;

        if(right)
          return right;

        return root;    
    }
};
