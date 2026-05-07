class Node {
    public:
        int key;
        int value;
        Node * next=nullptr;
        Node * prev=nullptr;
};
class LRUCache {
    
public:
    int cap;
    Node * head=nullptr;
    Node * left,*right;
    map<int, Node *> mapping;
    LRUCache(int capacity) {
        cap=capacity;
        left = new Node();
        right = new Node();
        left->next=right;
        right->prev=left;
    }
    void remove(Node * node)
    {
        Node * prev = node->prev;
        Node * nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }
    void insert(Node * node)
    {
        Node * nxt = left->next;
        left->next=node;
        node->next = nxt; 
        node->prev = left;
        nxt->prev = node;
    }

    int get(int key) {
        if(mapping.find(key)!=mapping.end())
        {
            Node * node = mapping[key];
            remove(node);
            insert(node);
            return node ->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mapping.find(key)!=mapping.end())
            remove(mapping[key]);
        
        Node * node = new Node();
        node->value = value;
        node->key = key;
        mapping[key] = node;
        insert(node);

        if(mapping.size()>cap)
        {
            Node * lru = right->prev;
            remove(lru);
            mapping.erase(lru->key);
            delete lru;
        }
        
    }
};
