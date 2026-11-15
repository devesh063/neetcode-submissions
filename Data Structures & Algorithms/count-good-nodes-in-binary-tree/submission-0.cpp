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
    void findGoodNode(TreeNode *root, int maxSoFar, int &cnt)
    {
        if(!root)
          return ;
        

        if(root->val >= maxSoFar)
        {
           ++cnt;
           maxSoFar = root->val;
        }

        findGoodNode(root->left, maxSoFar, cnt);

        findGoodNode(root->right, maxSoFar, cnt);
    }
    int goodNodes(TreeNode* root) 
    {
        int cnt = 0;

        findGoodNode(root,INT_MIN,cnt);

        return cnt;    
    }
};
