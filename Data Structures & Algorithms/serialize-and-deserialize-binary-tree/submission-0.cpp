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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string data;
        queue<TreeNode*> q;  q.push(root);

        while(!q.empty())
        {
            int size = q.size();

            for(int i=0; i < size; i++)
            {
                auto it = q.front(); q.pop();
                
                if(!it)
                {
                 data += "$#"; continue;
                }
                data += to_string(it->val) + "#";

                q.push(it->left);
                q.push(it->right);
            }
        }

        cout << "data :" << data << "\n";
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        stringstream ss(data);
        string s;
        vector<string> aux;

        while(getline(ss,s,'#'))
        {
            aux.push_back(s);
        }

        TreeNode *root = (aux[0] == "$" ? nullptr : new TreeNode(stoi(aux[0])));
        
        if(!root)
          return root;

        queue<TreeNode*> q;  q.push(root);

        for(int idx =  1; idx < aux.size(); idx++)
        {
            TreeNode *temp = q.front(); q.pop();
            
            if(aux[idx] != "$")
            {
                temp->left = new TreeNode(stoi(aux[idx]));
                q.push(temp->left);
            }

            idx++;

            if(aux[idx] != "$")
            {
               temp->right = new TreeNode(stoi(aux[idx]));
               q.push(temp->right);
            }
        }

        return root;    
    }
};
