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
        if(head==nullptr || head->next ==nullptr)
            return false;
        ListNode * first = head->next,*second = head;
        while(first!=nullptr){
            if(first==second)
                return true;
            if(first->next!=nullptr)
                first=first->next->next;
            else 
                break;
            second=second->next;
        }
        return false;
    }
};
