/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*,Node*> m;
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return nullptr;
        if(m.count(node))
                return m[node];
        cout<<"node->val : "<<node->val<<endl;
        Node * temp = new Node(node->val);
        m[node]=temp;
        for(int i=0;i<node->neighbors.size();i++)
        {
            cout<<node->neighbors[i]->val<<endl;
            temp->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return temp;
    }
};
