class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int counts[30000] = {0};
        counts[0]++; // base case
        
        int prev = 0;
        for(int i=0; i<nums.size(); i++) {
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