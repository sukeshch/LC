class Solution {
public:
    string transform(std::string& input) {
        string transformed_output(input);
        
        for(int i=0; i<input.size(); i++) {
            transformed_output[i] = 'a' + (26+input[i]-input[0])%26;
        }
        // cout << input << " -- " << transformed_output << endl;
        return transformed_output;
    }
    
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, vector<string>> mp;
        
        for(auto str : strings) {
            mp[transform(str)].push_back(str);
        }
        
        vector<vector<string>> results;
        std::transform(mp.begin(), mp.end(), std::back_inserter(results),
                   [](auto&& pair) { return std::move(pair.second); });
        
        return results;
    }
};