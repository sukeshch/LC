class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long, int> mp;
        int N = nums.size();
        
        long sum = 0;
        int longest = 0;
        for(int i = 0; i < N; i++) {
            sum += nums[i];
            if(sum == k) {
                longest = i+1;
            }
            
            if(mp.count(sum - k)) {
                longest = max(longest, i-mp[sum-k]);
            }
            
            if(!mp.count(sum)) {
                mp[sum] = i;
            }
        }
            
        return longest;
    }
};