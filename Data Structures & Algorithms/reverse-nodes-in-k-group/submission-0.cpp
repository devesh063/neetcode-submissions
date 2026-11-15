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
        ListNode *slow = head, *fast = head;
        int len = 0;

        while(fast && fast->next)
        {
            ++len;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(!fast)
          return 2 * len;
        return 2 * len + 1;
    }
    ListNode *reverse(ListNode *head, int k, int remLen)
    {
        if(!head || k > remLen)
         return head;

       ListNode *curr = head, *prev = nullptr; 
       int K = k;

        while(curr && K-- > 0)
        {
           ListNode *next =  curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;
        }

       head->next = reverse(curr,k,remLen - k);

       return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
       int len = findLen(head);
   
       return reverse(head, k, len);
    }
};
