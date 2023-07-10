class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        map<int, int> cmap;
        int sum = 0;
        cmap[sum] = 1;
        for(int i=0; i < nums.size(); i++) {
            sum += nums[i];
            if (cmap.find(sum - k) != cmap.end())
                result += cmap[sum-k];
            cmap[sum]++;
        }
        
        return result;
    }
};