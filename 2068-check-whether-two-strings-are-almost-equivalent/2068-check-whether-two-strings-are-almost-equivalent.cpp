class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int a[26] = {0};
        int result = 0;
        for(auto c : word1) {
            a[c-'a']++;
            if(a[c-'a'] == 4) result++;
        }
        for(auto c : word2) {
            if(a[c-'a'] == 4) result--;
            a[c-'a']--;
            if(a[c-'a'] == -4) result++;
        }
        return result == 0;
    }
};