class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        std::priority_queue<std::tuple<int,int>> q1;
        for(int i=0; i<k; i++)
        {
            q1.push(std::make_tuple(nums[i], i));
        }
        result.push_back(std::get<0>(q1.top()));
        
        for(int i=k; i<nums.size(); i++)
        {
            q1.push( std::make_tuple(nums[i], i) );
            while(std::get<1>(q1.top()) <= (i-k))
            {
                q1.pop();
            }
            result.push_back(std::get<0>(q1.top()));
        }

        return result;
    }
};