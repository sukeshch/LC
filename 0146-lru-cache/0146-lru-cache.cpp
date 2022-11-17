class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if(_cache.count(key)==0) return -1;
        mru.erase(_cache[key].second);
        mru.push_front(key);
        _cache[key].second = mru.begin();
        return _cache[key].first;
    }
    
    void put(int key, int value) {
        if(_cache.count(key) == 0) {
            if(_cache.size() == _capacity) 
            {
                _cache.erase(mru.back());
                mru.pop_back();
            }
        } else { // update and insert front
            mru.erase(_cache[key].second);
        }
        mru.push_front(key);
        _cache[key] = {value, mru.begin()};
    }
    

private:
    int _capacity;
    // key -> (value, index in mru)
    unordered_map<int, pair<int, list<int>::iterator>> _cache;
    list<int> mru;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */