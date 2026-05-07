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
    ListNode * reverseList(ListNode * head, ListNode * last)
    {
        cout<<head->val<<"->"<<last->val<<endl;
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode *temp = last->next,* prev = head , *curr = head->next , * currnext;
        last->next=nullptr;
        currnext = head->next->next;
        while(curr!=nullptr)
        {
            curr->next=prev;
            prev = curr;
            curr = currnext;
            if(currnext != nullptr)
                currnext = currnext->next;
        }
        head->next=temp;
        return last;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        ListNode *temp=head ,*headNode , *tempstart, *lastNode ,*start, *nextGrp ;
        int pos=1;
        start=new ListNode();
        start->next=head;
        tempstart=start;
        while(temp!=nullptr)
        {
            cout<<"temp->val : "<<temp->val<<endl;
            if(pos==1)
                headNode = temp;
            else if(pos==k)
            {
                nextGrp = temp->next;
                tempstart->next = reverseList(headNode,temp);
                temp=nextGrp;
                tempstart = headNode;
                pos=0;
            }
            if(pos!=0)
                temp=temp->next;
            pos++;
        }
        return start->next;
    }
};
