class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        // // a S1, a 
        int sz = 0;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            sz = result.size();
            for(int k = 0; k < sz; k++)
            {
                auto temp = result[k];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
            vector<int> c(1,nums[i]);
            result.push_back(c);
        }
        vector<int> c;
        result.push_back(c);
        set<vector<int>> s;
        for(auto k : result)
            s.insert(k);
        vector<vector<int>> rr(s.size());
        std::copy(s.begin(), s.end(), rr.begin());

        // int pw = pow(2, nums.size());
        // for(int i=0; i<pw; i++)
        // {
        //     bitset<10> b(i);
        //     vector<int> current;
        //     current.resize(b.count());
        //     int ct = 0;
        //     for(int i=0; i<nums.size(); i++)
        //     {
        //         if(b[i])
        //             current[ct++] = nums[i];
        //     }
        //     result.push_back(current);
        // }
        return rr;
    }
};