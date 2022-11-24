class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int a[26] = {0};
        for(auto c : word1) 
            a[c-'a']++;
        for(auto c : word2) 
            a[c-'a']--;
        for(auto v : a) 
            if(abs(v) > 3) return false;
        
        return true;
    }
};