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

 class compare
 {
public:
   //functors
   bool operator()(const auto &it1, const auto &it2)
   {
      return (it1->val > it2->val);
   }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
       priority_queue<ListNode*, vector<ListNode*>, compare> pq;


       for(auto &it : lists)
       {
        if(it)
         pq.push(it);
       }  

       ListNode dummy; ListNode *tail = &dummy;

       while(!pq.empty())
       {
          auto it = pq.top(); pq.pop();

          ListNode *next = it->next;

          tail->next = it;
          tail = tail->next;
          

          if(next)
            pq.push(next);
       }
       return dummy.next;
    }
};
