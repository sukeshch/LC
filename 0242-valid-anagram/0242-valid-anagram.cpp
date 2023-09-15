class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        int counts[26] {0};
        for(auto c : s)
            counts[c-'a']++;
        for(auto c : t) {
            counts[c-'a']--;
            if(counts[c-'a'] < 0) 
                return false;
        }
        for(int i=0; i<26; i++)
            if(counts[i] > 0) return false;
        return true;
    }
};