/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node * copyList(Node * head,unordered_map<Node*,Node*> & mNode)
    {
        if(head == nullptr)
            return nullptr;
        
        Node * ans = new Node(head->val);
        ans->next = copyList(head->next,mNode);
        mNode[head] = ans;
        return ans;
    }
    Node* copyRandomList(Node* head) {
        if(head==nullptr )
            return nullptr;

        unordered_map<Node*,Node*> mNode;
        Node *temp,*temphead,*ans = copyList(head,mNode);
        temp=ans;
        temphead=head;
        while(temphead!=nullptr)
        {
            temp->random = mNode[temphead->random];
            cout<<"mNode[temp->random] : "<<mNode[temp->random]<<endl;
            temp=temp->next;
            temphead=temphead->next;
        }
        return ans;
    }
};
