class Solution { 
public: 
    int minimumSum(vector<int>& nums) { 
        vector<int> lsum(nums.size(), 0), rsum(nums.size(), 0);
        lsum[0] = nums[0];
        for(int i=1; i<nums.size(); i++) {
            lsum[i] = min(lsum[i-1], nums[i]);
        }
        rsum[nums.size()-1] = nums.back();
        for(int i=nums.size()-2; i >= 0; i--) {
            rsum[i] = min(rsum[i+1], nums[i]);
        }
        int result = INT_MAX;
        for(int i=1; i<nums.size()-1; i++) {
            if(nums[i] > lsum[i-1] && nums[i] > rsum[i+1]) {
                result = min(result, lsum[i-1] + nums[i] + rsum[i+1]);
            }
        }
        return result == INT_MAX ? -1 : result;
    } 
}; 
