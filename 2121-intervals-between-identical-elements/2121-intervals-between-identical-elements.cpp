class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<long long>> mp;
        vector<long long> result(arr.size(), 0);
        
        for(int i=0; i<arr.size(); i++) {
            if(mp.count(arr[i]) == 0) {
                mp[arr[i]].push_back(0);
            }
            mp[arr[i]].push_back(i);
            mp[arr[i]][0] += i;
        }
        for(auto& [key, value] : mp) {
            long long sum = 0;
            // i*cur - sum + (t-sum-cur) - cur * (s-1-i)
            long long sz = value.size() - 1;
            for(int i=1; i<value.size(); i++) {
                result[value[i]] = 
                    (i-1) * value[i] - sum + 
                    (value[0] - sum - value[i]) - (sz - 1 - (i-1)) * value[i];
                
                sum += value[i];
            }
        }
        
        return result;
    }
};