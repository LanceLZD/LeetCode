class LRUCache {
private:
    unordered_map<int, list<pair<int,int>>::iterator> m;
    list<pair<int,int>> l;
    int s;
public:
    LRUCache(int capacity) {
        s = capacity;
    }
    
    int get(int key) {
        int res = -1;
        auto it = m.find(key);
        if (it!=m.end()) {
            res = it->second->second;
            l.splice(l.begin(), l, it->second);
        }
        return res;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it!=m.end()) {
            it->second->second = value;
            l.splice(l.begin(), l, it->second);
        }
        else {
            l.insert(l.begin(), make_pair(key, value));
            m[key] = l.begin();
            if (l.size()>s) {
                m.erase(l.back().first);
                l.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */