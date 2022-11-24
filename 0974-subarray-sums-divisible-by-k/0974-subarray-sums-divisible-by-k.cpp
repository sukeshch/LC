class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> counts(k, 0);
        counts[0]++;
        int prev = nums[0];
        
        prev = nums[0];
        prev = prev % k;
        if(prev < 0) prev += k;
        counts[prev]++;
        
        for(int i=1; i<nums.size(); i++) {
            prev += nums[i];
            prev = prev % k;
            if(prev < 0) prev+=k;
            counts[prev]++;
        }
        int res = 0;
        for(auto c : counts) {
            res += (c * (c-1)) / 2;
        }
        return res;
    }
};