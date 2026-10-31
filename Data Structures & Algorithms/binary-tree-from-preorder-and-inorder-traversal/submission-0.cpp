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
    TreeNode *constructTree(vector<int> &preorder, int &preIdx, int start, int end, map<int,int> &inorderMap)
    {
        if(start > end)
          return nullptr;
          
         TreeNode *root = new TreeNode(preorder[preIdx++]);

         root->left = constructTree(preorder,preIdx,start,inorderMap[root->val]-1,inorderMap);
         root->right = constructTree(preorder,preIdx,inorderMap[root->val]+1,end,inorderMap);

         return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
       map<int,int> inorderMap;
       int preIdx = 0; int n = preorder.size();
       for(int i=0; i<inorder.size(); i++)
       {
          inorderMap[inorder[i]] = i;
       }    

       return constructTree(preorder,preIdx,0,n-1,inorderMap);
    }
};
