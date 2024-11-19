class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum = 0;
        int K = 2*k + 1;
        
        vector<int> res(nums.size(), -1);
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if(i >= (K-1)) 
            {
                res[i-k] = sum / K;
                sum -= nums[i-K+1];
            }
        }
        
        return res;
    }
};