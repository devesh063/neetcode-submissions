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

#define ll long long
class Node
{
public:
   bool isBst;
   ll  maxNode;
   ll  minNode;

   Node(bool _isBst, ll _maxNode, ll _minNode)
   {
      isBst = _isBst;
      maxNode = _maxNode;
      minNode = _minNode;
   }
};

class Solution {
public:
    Node isBst(TreeNode *root)
    {
        if(!root)
          return Node(true,LONG_MIN,LONG_MAX);

        Node left = isBst(root->left);

        Node right = isBst(root->right);
        
        if(!left.isBst || !right.isBst)
           return Node(false,0,0);

        if(root->val <= left.maxNode || root->val >= right.minNode)
           return Node(false,0,0);
        
        ll minVal = min((ll)root->val,left.minNode);
        ll maxVal = max((ll)root->val,right.maxNode);

        return Node(true,maxVal,minVal);
    }
    bool isValidBST(TreeNode* root) 
    {
        return isBst(root).isBst;    
    }
};
