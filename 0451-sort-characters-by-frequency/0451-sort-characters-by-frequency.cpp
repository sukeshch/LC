class Solution {
public:
    string frequencySort(string s) {
        vector<int> counts(256, 0);
        for(unsigned char c : s) {
            counts[c]++;
        }
        map<int, vector<char>> mp_;
        for(int i=0; i<256; i++) {
            if(counts[i] != 0) {
                mp_[counts[i]].push_back((unsigned char) i);
            }
        }
        string result = "";
        for (auto it = mp_.rbegin(); it != mp_.rend(); it++) 
        {
            for(auto c : it->second)
                result += std::string(it->first, c);
        }
        return result;
    }
};