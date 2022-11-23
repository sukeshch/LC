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
    
    bool cmp(pair<int, int> const& l, pair<int, int> const& r)
    {
        // For instance...
        return l.first < r.second;
    }
    
    int get(int index, int snap_id) {
        if(mp_.count(index) == 0) return 0;
        
        for(auto s : db_[mp_[index]])
        {
            if(s.first == snap_id) return s.second;
        }
        // int l = 0, n = db_[mp_[index]].size()-1;
        // if(n > 0) {
        //     if(db_[mp_[index]][0].first == snap_id) return db_[mp_[index]][0].second;
        //     if(db_[mp_[index]][n-1].first == snap_id) return db_[mp_[index]][n-1].second;
        // }
        // int count = n-l+1, it, step;
        // while(count > 0) {
        //     it = l; step=count/2; it+= step;
        //     if (!(snap_id<db_[mp_[index]][it].first))                 // or: if (!comp(val,*it)), for version (2)
        //       { l=++it; count-=step+1;  }
        //     else count=step;
        // }
        // if(it == 0) return 0;
        // it--;
        // if(db_[mp_[index]][it].first == snap_id) return db_[mp_[index]][it].second;
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