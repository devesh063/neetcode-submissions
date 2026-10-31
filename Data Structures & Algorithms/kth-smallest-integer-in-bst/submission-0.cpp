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
    void findKthSmallest(TreeNode *root, int &k, int &smallest)
    {
        if(!root)
          return ;
        
        if(smallest != (int)1e9)
          return ;

        findKthSmallest(root->left,k,smallest);
        if(--k == 0)
        {
            smallest = root->val;
            return ;
        }
        findKthSmallest(root->right,k,smallest);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        int smallest = (int)1e9;

        findKthSmallest(root,k,smallest);

        return smallest;    
    }
};
