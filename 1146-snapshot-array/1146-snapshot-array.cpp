class SnapshotArray {
public:
    SnapshotArray(int length) : N(length), snaps_(0), count(0) {
        current_.resize(length);
        db_.resize(length);
    }
    
    void set(int index, int val) {
        if(mp_.count(index) == 0){
            mp_[index] = count;
            count++;
        }
        current_[mp_[index]] = val;
    }
    
    int snap() {
        for(auto k : mp_) {
            db_[k.second].push_back({snaps_, current_[k.second]});
        }
        snaps_++;
        return snaps_-1;
    }
    
    int get(int index, int snap_id) {
        if(mp_.count(index) == 0) return 0;
        
        for(auto s : db_[mp_[index]])
        {
            if(s.first == snap_id) return s.second;
        }
        return 0;
    }
private: 
    unordered_map<int, int> mp_;
    vector< vector< pair<int, int> >> db_;
    vector<int> current_;
    int N;
    int snaps_;
    int count;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */