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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next ==nullptr)
            return head;
        ListNode * prev,*temp,*temp_2;
        prev=head;
        temp=head->next;
        prev->next=nullptr;
        while(temp!=nullptr)
        {
            temp_2 = (temp->next!=nullptr)?temp->next:nullptr;
            temp->next=prev;
            prev=temp;
            temp=temp_2;
        }

        return prev;
    }
};
