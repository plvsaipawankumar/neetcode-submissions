class TimeMap {
public:
    map<string , map<int,string>> moods;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        moods[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it= moods[key].upper_bound(timestamp);
        return it == moods[key].begin()?"":prev(it)->second;
    }
};
