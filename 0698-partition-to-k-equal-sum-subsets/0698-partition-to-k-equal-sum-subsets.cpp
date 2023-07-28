class Solution {
public:
    bool recurse(int nidx, bitset<16> b,  
                 int distribute, 
                 vector<int>& nums, 
                 int k, int bucket, int prev_index,
                 unordered_map<unsigned long, bool> &mp)    {
        if(mp.count(b.to_ulong()))
            return mp[b.to_ulong()];
        if(nidx == k - 1) {
            return true;
        }
        
        for(int i=prev_index; i < nums.size(); i++) {
            if(!b.test(i)) {
                if(distribute + nums[i] > bucket) continue;
               
                b.set(i);
                distribute += nums[i];
                if(recurse(
                    (distribute == bucket)
                        ? nidx + 1 : nidx, 
                    b, 
                    (distribute ==  bucket) ? 0 : distribute, 
                    nums, k, bucket, 
                (distribute ==  bucket) ? 0 : i, mp))
                    return true;
                distribute -= nums[i];
                b.reset(i);
            }
        }
        mp[b.to_ulong()] = false;
        return mp[b.to_ulong()];
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto n : nums) sum += n;
        if(sum % k != 0) return false;
        bitset<16> b(0);
        sort(nums.begin(), nums.end(), std::greater<int>());
        unordered_map<unsigned long, bool> mp;
        return recurse(0, b, 0, nums, k, sum/k, 0, mp);
    }
};