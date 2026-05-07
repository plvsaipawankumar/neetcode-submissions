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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;

        ListNode * prev1 , *prev2 ,* temp1, *temp2 ,*ans;
        if(list1->val>list2->val)
        {
            ans=list1;
            list1=list2;
            list2=ans;
        }
        prev1 = list1; temp1=list1->next;
        prev2 = list2; temp2=list2->next;
        while(temp1!=nullptr && prev2!=nullptr)
        {
            if(temp1->val>prev2->val)
            {
                prev1->next=prev2;
                prev2->next=temp1;
                prev1=prev2;
                prev2=temp2;
                if(temp2!=nullptr)
                    temp2=temp2->next;
            }
            else
            {
                prev1=temp1;
                temp1=temp1->next;
            }
        }
        if(prev2!=nullptr)
            prev1->next=prev2;

        return list1;
    }
};
