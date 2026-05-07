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
    pair<int,ListNode*> smallestList(vector<ListNode*>& lists)
    {
        int i,n=lists.size(),min=INT_MAX;
        pair<int,ListNode*> response = {INT_MIN,nullptr};
        for(i=0;i<n;i++)
        {
            if(lists[i]!=nullptr && (min > lists[i]->val))
            {
                response = {i,lists[i]};
                min=lists[i]->val;
            }
        }
        return response;
    }

    ListNode* addElement(int val)
    {
        ListNode * create = new ListNode(val);
        return create;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *temp,*ans,* head = nullptr;
        int i,n=lists.size();
        pair<int,ListNode*> helper ;
        while(true)
        {
            helper=smallestList(lists);
            if(helper.first==INT_MIN)break;
            ans=addElement(lists[helper.first]->val);
            lists[helper.first]=lists[helper.first]->next;
            if(head==nullptr)
                temp=head=ans;
            else 
            {
                temp->next=ans;
                temp=temp->next;
            }
        }
        return head;
    }
};
