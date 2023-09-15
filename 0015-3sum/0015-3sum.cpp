class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i < nums.size()-2 && nums[i] <= 0; i++) {
            if(i!=0 && nums[i] == nums[i-1]) 
                continue;
            int start = i+1, end = nums.size()-1, sum;
            while(start < end) {
                sum = nums[i] + nums[start] + nums[end];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[start++], nums[end--]});
                    
                    while(start < end && nums[start] == nums[start-1]) 
                        start++;
                } else if(sum > 0) {
                    end--;
                } else {
                    start++;
                }
            }
         }
        return ans;
    }
};