class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> cmap;
        int sum = 0;
        cmap[sum] = 1;
        for(int i=0; i < nums.size(); i++) {
            sum += nums[i];
            if (cmap.count(sum - k))
                result += cmap[sum-k];
            cmap[sum]++;
        }
        
        return result;
    }
};