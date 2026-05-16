class Node
{
    public :
        int key;
        int value;
        Node * next =nullptr;
        Node * prev =nullptr;
};
class LRUCache {
public:
    int cap;
    map<int,Node*> cache;
    Node * left, * right;
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node();
        right = new Node();
        left ->next = right;
        right -> prev = left;
    }
    void remove(Node * node)
    {
        Node * prev = node->prev;
        Node * nxt = node->next;
        prev->next=nxt;
        nxt->prev=prev;
    }
    void insert(Node * node)
    {
        Node * nxt = left -> next;
        nxt -> prev=node;
        node->prev = left;
        node->next=nxt;
        left->next=node;

    }
    int get(int key) {
        if(cache.find(key)==cache.end())
            return -1;
        Node * store = cache[key];
        remove(store);
        insert(store);
        return store->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
            remove(cache[key]);
        Node * newnode = new Node();
        newnode -> value = value;
        newnode -> key = key;
        cache[key] = newnode;
        insert(newnode);
        if(cache.size()>cap)
        {
            Node * lru = right->prev;
           remove(lru);
           cache.erase(lru->key);
           delete lru;
        } 
    }
};
