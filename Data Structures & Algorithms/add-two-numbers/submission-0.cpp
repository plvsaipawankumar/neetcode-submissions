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

    ListNode* additionList(ListNode * l1,ListNode * l2, int & carry)
    {
        if(l1==nullptr && l2==nullptr && carry==0)
            return nullptr;
        ListNode * ans = new ListNode(); 
        if(l1==nullptr && l2==nullptr)
        {
            ans->val = carry;
            return ans;
        }
        else if(l1==nullptr)
        {
            ans->val = (l2->val + carry)%10;
            carry = ((l2->val + carry)/10);
            ans->next = additionList(l1 , l2->next , carry );
        }
        else if(l2==nullptr)
        {
            ans->val = (l1->val + carry)%10;
            carry = ((l1->val + carry)/10);
            ans->next = additionList(l1->next , l2 , carry );
        }
        else
        {
            ans->val = (l1->val+l2->val + carry)%10;
            cout<<"ans->val : "<<ans->val<<endl;
            carry = ((l1->val + l2->val + carry)/10);
            ans->next = additionList(l1->next ,l2->next , carry );
        }
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode * ans = additionList(l1,l2,carry);
        return (ans);
    }
};
