class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& input) {
        
        unordered_map<string, vector<string>> mp_;
        for (int i=0; i<input.size(); i++) {
            string in = input[i];
            sort(in.begin(), in.end());
            mp_[in].push_back(input[i]);
        }
        
        vector<vector<string>> ans; 
        for(auto p : mp_) {
            ans.push_back(p.second);
        }
        return ans;
    }
};