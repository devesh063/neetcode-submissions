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
    int findMaxPath(TreeNode *root, int &maxPath)
    {
        
       if(!root)
         return (int)-1e9;

       int lSum = findMaxPath(root->left,maxPath);

       int rSum = findMaxPath(root->right,maxPath);

       int sum = root->val + (lSum< 0 ? 0 : lSum) + (rSum < 0 ? 0 : rSum);
      
       maxPath = max(maxPath,sum);

       //cout<< "maxPath :" << maxPath << "val :" << root->val << " " << "lSum :" << lSum << " " << "rSum :" << rSum << " " << "ret val :" << max(root->val,sum) << "\n";

       return max(root->val, max(lSum,rSum) + root->val);
    }
    int maxPathSum(TreeNode* root) 
    {
        int maxPath = (int)-1e9;

        findMaxPath(root,maxPath);

        return maxPath;
    }
};
