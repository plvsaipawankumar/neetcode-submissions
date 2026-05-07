class LRUCache {
private :
    int priority =0;
    int limit;
    unordered_map<int,pair<int,list<int>::iterator>>  umap;
    //vector<int> order;
    list<int> order;
    
public:
    
    LRUCache(int capacity) {
        limit = capacity;
    }
    
    int get(int key) {
        if(umap.find(key)==umap.end()) return -1;
        order.erase(umap[key].second);
        order.push_back(key);
        umap[key].second=--order.end();
        cout<<"umap[key].first :"<<umap[key].first<<endl;
        return umap[key].first;
    }
    
    void put(int key, int value) {
        cout<<"key  :"<<key<<"umap.size() :"<<umap.size()<<endl;
        if(umap.find(key)!=umap.end())
        {
            order.erase(umap[key].second);
        }
        else if(umap.size()==limit)
        {
            auto it = order.front();
            order.pop_front();
            umap.erase(it);
        }
        order.push_back(key);
        umap[key]={value,--order.end()};
    }
};
