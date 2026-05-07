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
    void removeElement(ListNode* head , int & n, bool & ans)
    {
        if(head==nullptr)return ;
        removeElement(head->next,n,ans);
        cout<<"n : "<<n<<" , head->val : "<<head->val<<endl;
        if(n==0)
        {
            head->next=head->next->next;
            ans=true;
        }
        n--;
        return ;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        bool ans;
        removeElement(head,n,ans);
        return (ans)?head:head->next;
    }
};
