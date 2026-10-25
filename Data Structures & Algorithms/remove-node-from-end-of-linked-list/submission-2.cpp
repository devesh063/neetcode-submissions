/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    int findLen(ListNode *head)
    {
        int len = 0;

        ListNode *slow = head, *fast = head;

        while(fast && fast->next)
        {
            ++len;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(!fast)
          return 2*len;
        return 2*len + 1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
         int len = findLen(head); 
         
         if(len < n)  return head;

         int k =  len - n;

         if(k == 0)
           return head->next;

         //cout << k << "\n";
         ListNode *curr = head;
         
         while(curr && k-- > 1)
         {
            curr = curr->next;
         }   
         //cout<< ":" << curr->val << "\n";
         if(curr)
            curr->next = curr->next ? curr->next->next : nullptr;
        
        return head;
    }
};
