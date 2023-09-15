class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& input) {
        vector<vector<string>> ans; 
        unordered_map<string, vector<string>> mp_;
        for (int i=0; i<input.size(); i++) {
            int counts[26] = {0};
            for (auto c : input[i]) {
                counts[c-'a']++;
            }
            string sortedinput = "";
            for(int k=0; k<26; k++) {
                sortedinput += string('a'+k, counts[k]);
            }
            mp_[sortedinput].push_back(input[i]);
        }
        
        for(auto p : mp_) {
            ans.push_back(p.second);
        }
        return ans;
    }
};