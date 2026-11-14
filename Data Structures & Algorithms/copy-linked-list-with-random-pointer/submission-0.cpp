/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void copy(Node* head, unordered_map<Node*,Node*> &map)
    {
        if(!head)
          return ;
        
        Node *newNode = new Node(head->val);
        
        map[head] = newNode;

        copy(head->next,map);
    }
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*,Node*> map;

        copy(head,map); 

        Node *curr = head;

        while(curr)
        {
            map[curr]->next = map[curr->next];
            map[curr]->random = map[curr->random];

            curr = curr->next;
        }       

        return map[head];
    }
};
