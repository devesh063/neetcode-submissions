
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        // 1. Find the end of the first half
        ListNode* mid = findMid(head);

        // 2. Split the list into two halves
        ListNode* second = mid->next;
        mid->next = nullptr;

        // 3. Reverse the second half
        second = reverseLinkedList(second);

        // 4. Merge the two halves alternately
        ListNode* first = head;

        while (second) {
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;

            first->next = second;
            second->next = nextFirst;

            first = nextFirst;
            second = nextSecond;
        }
    }
};
