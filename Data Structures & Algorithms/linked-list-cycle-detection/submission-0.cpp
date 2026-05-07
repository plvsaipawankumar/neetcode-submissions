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
    bool hasCycle(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return false;
        ListNode * slow , * fast;
        slow= head;
        fast = head->next;
        while(slow!=fast && fast != nullptr)
        {
            slow=slow->next;
            if(fast->next == nullptr)
                return false;
            fast=fast->next->next;
        }
        return (slow==fast)? true: false;
    }
};
