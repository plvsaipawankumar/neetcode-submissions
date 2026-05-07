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
    ListNode * reverseListNode(ListNode * head)
    {
        if(head->next==nullptr)
            return head;
        
        ListNode * slow ,* temp,*temp_2;
        slow = head;
        temp = head->next;

        while(temp!=nullptr)
        {
            temp_2 = temp->next;
            temp->next=slow;
            slow=temp;
            temp=temp_2;
        }
        head->next = nullptr;
        return slow;
    }
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return ;
        
        ListNode *slow ,*fast,*temp,*fasttemp;
        slow = head;
        fast = head->next;

        while(fast!=nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        temp=reverseListNode(slow->next);
        slow->next=nullptr;
        slow=head;
        fast=slow->next;
        fasttemp=temp->next;
        while(temp!=nullptr)
        {
            slow->next=temp;
            temp->next=fast;
            temp=fasttemp;
            slow=fast;
            if(fast!=nullptr)
                fast=fast->next;
            if(fasttemp!=nullptr)
                fasttemp=fasttemp->next;
        }

        return;
    }
};
