class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long> sum(nums.size()+1, 0);
        int n=nums.size();
        sum[0] = nums[0];
        for(int i=1; i < nums.size(); i++) {
            sum[i] += sum[i-1] + nums[i];
        }
        sum[n] = sum[n-1];
        int result = 0;
        int minV = 100000;
        for(int i=0; i<n; i++) {
            int temp = abs( sum[i]/(i+1) - 
                            ((n-i-1) ? ((sum[n]-sum[i])/(n-i-1)) : 0) );
            if (temp < minV)
            {
                minV = temp;
                result = i;
                cout << result << " ";
            }
        }
        
        return result;
    }
};