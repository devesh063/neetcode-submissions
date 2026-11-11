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
    vector<int> rightSideView(TreeNode* root) 
    {
       if(!root) return {};
       vector<int> ans;
       queue<TreeNode*> q; q.push(root);    

       while(!q.empty())
       {
          int len = q.size();

          for(int idx = 0; idx <len; idx++)
          {
             TreeNode *temp = q.front(); q.pop();

             if(idx == len-1) ans.push_back(temp->val);

             if(temp->left)
               q.push(temp->left);
             if(temp->right)
               q.push(temp->right);
          }
       }
       return ans;
    }
};
