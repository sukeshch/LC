class Solution {
public:
    // type 0(2), 1(3), 2 (3 consecutive) 
    bool recurse(vector<int>& n, int i, map<int,int> &mp) {
        if(mp.count(i))
            return mp[i];
        if(i >= n.size()) return true;
        bool res = false;
        
        if((i+1 < n.size()) && n[i] == n[i+1])
            res |= recurse(n, i+2, mp);
        
        if((i+2 < n.size()) && n[i] == n[i+1] && n[i+1] == n[i+2])
            res |= recurse(n, i+3, mp);
        
        if((i+2 < n.size()) && n[i]+1 == n[i+1] && n[i+1]+1 == n[i+2])
            res |= recurse(n, i+3, mp);
        
        mp[i] = res;
        return res;
    }
    
    
    bool validPartition(vector<int>& nums) {
        map<int,int> mp;
        return recurse(nums, 0, mp);
    }
};